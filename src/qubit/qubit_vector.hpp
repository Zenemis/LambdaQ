#ifndef QUBIT_VECTOR_HPP
#define QUBIT_VECTOR_HPP

#include <memory>
#include <complex>
#include <stdexcept>
#include <cmath>
#include <cstdlib>

#include <qubit.hpp>

#include <Eigen/Dense>

namespace lambdaq::qgate { class QGateVector; }

#include <structs/bloch_sphere.hpp>
#include <structs/bloch_sphere/bsphere_angles.hpp>

namespace lambdaq::qubit {

class QubitVector : public lambdaq::Qubit {

public:
    friend class lambdaq::qgate::QGateVector;

    QubitVector() {
        state = Eigen::Matrix<std::complex<double>, 2, 1>::Zero();
        state(0) = 1.0; // Initialize to |0> state
    }

    QubitVector(const Eigen::Matrix<std::complex<double>, 2, 1>& state) : state(state) {
        // Ensure the coefficients are normalized
        double norm = state.norm();
        if (std::abs(norm - 1.0) > 1e-6) {
            throw std::invalid_argument("The coefficients must be normalized (|a|^2 + |b|^2 = 1).");
        }
    }

    virtual ~QubitVector() = default;

    virtual bool collapse() override {
        // Simulate a collapse based on the probability of the |1> state
        double probability = getProbability();
        return (rand() / static_cast<double>(RAND_MAX)) < probability;
    }

    virtual double getProbability() const override {
        // Calculate the probability of the |1> state
        return std::norm(state(1));
    }

    virtual std::complex<double> getZeroCoeff() const override {
        return state(0);
    }

    virtual std::complex<double> getOneCoeff() const override {
        return state(1);
    }

    virtual double getPhase() const override {
        // Calculate the relative phase between |0> and |1> states
        return std::arg(state(1)) - std::arg(state(0));
    }

    virtual const std::shared_ptr<lambdaq::structs::BlochSphere> getBlochSphere() const override {
        // Calculate the angles for the Bloch sphere representation
        double theta = 2 * std::acos(std::abs(state(0)));
        double phi = std::arg(state(1)) - std::arg(state(0));

        // Construct and return the Bloch sphere representation
        return std::make_shared<lambdaq::structs::bsphere::BSphereAngles>(theta, phi);
    }

private:
    Eigen::Matrix<std::complex<double>, 2, 1> state; // State vector: [|0>, |1>]
};

} // namespace lambdaq::qubit

#endif // QUBIT_VECTOR_HPP