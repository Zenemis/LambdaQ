#ifndef QUBIT_COEFFS_HPP
#define QUBIT_COEFFS_HPP

#include <memory>
#include <complex>
#include <stdexcept>
#include <cmath>
#include <cstdlib>

#include <qubit.hpp>

#include <structs/bloch_sphere.hpp>
#include <structs/bloch_sphere/bsphere_angles.hpp>

namespace lambdaq::qubit {

class QubitCoeffs : public lambdaq::Qubit {

public:
    QubitCoeffs()
        : coeff_zero(1.0, 0.0), coeff_one(0.0, 0.0) {
        // Default constructor initializes to |0> state
    }

    QubitCoeffs(std::complex<double> coeff_zero, std::complex<double> coeff_one)
        : coeff_zero(coeff_zero), coeff_one(coeff_one) {
        // Ensure the coefficients are normalized
        double norm = std::norm(coeff_zero) + std::norm(coeff_one);
        if (std::abs(norm - 1.0) > 1e-6) {
            throw std::invalid_argument("The coefficients must be normalized (|a|^2 + |b|^2 = 1).");
        }
    }

    virtual ~QubitCoeffs() = default;

    virtual bool collapse() override {
        // Simulate a collapse based on the probability of the |1> state
        double probability = getProbability();
        return (rand() / static_cast<double>(RAND_MAX)) < probability;
    }

    virtual double getProbability() const override {
        // Calculate the probability of the |1> state
        return std::norm(coeff_one);
    }

    virtual std::complex<double> getZeroCoeff() const override {
        return coeff_zero;
    }

    virtual std::complex<double> getOneCoeff() const override {
        return coeff_one;
    }

    virtual double getPhase() const override {
        // Calculate the relative phase between |0> and |1> states
        return std::arg(coeff_one) - std::arg(coeff_zero);
    }

    virtual const std::shared_ptr<lambdaq::structs::BlochSphere> getBlochSphere() const override {
        // Calculate the angles for the Bloch sphere representation
        double theta = 2 * std::acos(std::abs(coeff_zero));
        double phi = std::arg(coeff_one) - std::arg(coeff_zero);

        // Construct and return the Bloch sphere representation
        return std::make_shared<lambdaq::structs::bsphere::BSphereAngles>(theta, phi);
    }

private:
    std::complex<double> coeff_zero; // Coefficient for |0> state
    std::complex<double> coeff_one;  // Coefficient for |1> state

};
} // namespace lambdaq::qubit

#endif // QUBIT_COEFFS_HPP