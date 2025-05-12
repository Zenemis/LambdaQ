#include "qubit/qubit_bloch.hpp"
#include <stdexcept>

#include <memory>
#include <complex>

#include <structs/bloch_sphere.hpp>
#include <structs/bloch_sphere/bsphere_angles.hpp>
#include <structs/bloch_sphere/bsphere_coords.hpp>

namespace lambdaq::qubit {

QubitBloch::QubitBloch(std::unique_ptr<lambdaq::structs::BlochSphere> bloch_sphere)
    : bloch_sphere(std::move(bloch_sphere)) {}

QubitBloch::QubitBloch(double theta, double phi)
    : bloch_sphere(std::make_unique<lambdaq::structs::bsphere::BSphereAngles>(theta, phi)) {}

QubitBloch::QubitBloch(double x, double y, double z)
    : bloch_sphere(std::make_unique<lambdaq::structs::bsphere::BSphereCoords>(x, y, z)) {}

bool QubitBloch::collapse() {
    // Simulate a collapse based on the probability of the |1> state
    double probability = getProbability();
    return (rand() / static_cast<double>(RAND_MAX)) < probability;
}

double QubitBloch::getProbability() const {
    // Calculate the probability of the |1> state
    return std::norm(getOneCoeff());
}

std::complex<double> QubitBloch::getZeroCoeff() const {
    if (!bloch_sphere) {
        throw std::runtime_error("Bloch sphere is not initialized");
    }
    // Calculate the |0> coefficient from the Bloch sphere representation
    double theta = bloch_sphere->getTheta();
    return std::cos(theta / 2.0);
}

std::complex<double> QubitBloch::getOneCoeff() const {
    if (!bloch_sphere) {
        throw std::runtime_error("Bloch sphere is not initialized");
    }
    // Calculate the |1> coefficient from the Bloch sphere representation
    double theta = bloch_sphere->getTheta();
    double phi = bloch_sphere->getPhi();
    return std::sin(theta / 2.0) * std::exp(std::complex<double>(0, phi));
}

double QubitBloch::getPhase() const {
    if (!bloch_sphere) {
        throw std::runtime_error("Bloch sphere is not initialized");
    }
    // Return the phase of the Bloch sphere
    return bloch_sphere->getPhi();
}

const std::shared_ptr<lambdaq::structs::BlochSphere> QubitBloch::getBlochSphere() const {
    if (!bloch_sphere) {
        throw std::runtime_error("Bloch sphere is not initialized");
    }
    // Clone the inner object and return it as a shared_ptr
    return std::shared_ptr<lambdaq::structs::BlochSphere>(bloch_sphere->clone());
}

} // namespace lambdaq::qubit