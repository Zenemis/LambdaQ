#ifndef QUBIT_BLOCH_HPP
#define QUBIT_BLOCH_HPP

#include <memory>
#include <complex>
#include <stdexcept>
#include <cmath>
#include <cstdlib>

#include <qubit.hpp>

#include <structs/bloch_sphere.hpp>
#include <structs/bloch_sphere/bsphere_angles.hpp>
#include <structs/bloch_sphere/bsphere_coords.hpp>

namespace lambdaq::qubit {

class QubitBloch : public lambdaq::Qubit {

public:
    QubitBloch(std::unique_ptr<lambdaq::structs::BlochSphere> bloch_sphere)
        : bloch_sphere(std::move(bloch_sphere)) {}

    QubitBloch(double theta, double phi)
        : bloch_sphere(std::make_unique<lambdaq::structs::bsphere::BSphereAngles>(theta, phi)) {}

    QubitBloch(double x, double y, double z)
        : bloch_sphere(std::make_unique<lambdaq::structs::bsphere::BSphereCoords>(x, y, z)) {}

    virtual ~QubitBloch() = default;

    virtual bool collapse() override {
        // Simulate a collapse based on the probability of the |1> state
        double probability = getProbability();
        return (rand() / static_cast<double>(RAND_MAX)) < probability;
    }

    virtual double getProbability() const override {
        // Calculate the probability of the |1> state
        return std::norm(getOneCoeff());
    }

    virtual std::complex<double> getZeroCoeff() const override {
        if (!bloch_sphere) {
            throw std::runtime_error("Bloch sphere is not initialized");
        }
        // Calculate the |0> coefficient from the Bloch sphere representation
        double theta = bloch_sphere->getTheta();
        return std::cos(theta / 2.0);
    }

    virtual std::complex<double> getOneCoeff() const override {
        if (!bloch_sphere) {
            throw std::runtime_error("Bloch sphere is not initialized");
        }
        // Calculate the |1> coefficient from the Bloch sphere representation
        double theta = bloch_sphere->getTheta();
        double phi = bloch_sphere->getPhi();
        return std::sin(theta / 2.0) * std::exp(std::complex<double>(0, phi));
    }

    virtual double getPhase() const override {
        if (!bloch_sphere) {
            throw std::runtime_error("Bloch sphere is not initialized");
        }
        // Return the phase of the Bloch sphere
        return bloch_sphere->getPhi();
    }

    virtual const std::shared_ptr<lambdaq::structs::BlochSphere> getBlochSphere() const override {
        if (!bloch_sphere) {
            throw std::runtime_error("Bloch sphere is not initialized");
        }
        // Clone the inner object and return it as a shared_ptr
        return std::shared_ptr<lambdaq::structs::BlochSphere>(bloch_sphere->clone());
    }

private:
    std::unique_ptr<lambdaq::structs::BlochSphere> bloch_sphere;

};
} // namespace lambdaq::qubit

#endif // QUBIT_BLOCH_HPP