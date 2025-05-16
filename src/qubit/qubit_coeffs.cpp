#include <qubit/qubit_coeffs.hpp>
#include <stdexcept>
#include <cmath>

#include <structs/bloch_sphere/bsphere_angles.hpp>

namespace lambdaq::qubit {

QubitCoeffs::QubitCoeffs()
    : coeff_zero(1.0, 0.0), coeff_one(0.0, 0.0) {
    // Default constructor initializes to |0> state
}

QubitCoeffs::QubitCoeffs(std::complex<double> coeff_zero, std::complex<double> coeff_one)
    : coeff_zero(coeff_zero), coeff_one(coeff_one) {
    // Ensure the coefficients are normalized
    double norm = std::norm(coeff_zero) + std::norm(coeff_one);
    if (std::abs(norm - 1.0) > 1e-6) {
        throw std::invalid_argument("The coefficients must be normalized (|a|^2 + |b|^2 = 1).");
    }
}

bool QubitCoeffs::collapse() {
    // Simulate a collapse based on the probability of the |1> state
    double probability = getProbability();
    return (rand() / static_cast<double>(RAND_MAX)) < probability;
}

double QubitCoeffs::getProbability() const {
    // Calculate the probability of the |1> state
    return std::norm(coeff_one);
}

std::complex<double> QubitCoeffs::getZeroCoeff() const {
    return coeff_zero;
}

std::complex<double> QubitCoeffs::getOneCoeff() const {
    return coeff_one;
}

double QubitCoeffs::getPhase() const {
    // Calculate the relative phase between |0> and |1> states
    return std::arg(coeff_one) - std::arg(coeff_zero);
}

const std::shared_ptr<lambdaq::structs::BlochSphere> QubitCoeffs::getBlochSphere() const {
    // Calculate the angles for the Bloch sphere representation
    double theta = 2 * std::acos(std::abs(coeff_zero));
    double phi = std::arg(coeff_one) - std::arg(coeff_zero);

    // Construct and return the Bloch sphere representation
    return std::make_shared<lambdaq::structs::bsphere::BSphereAngles>(theta, phi);
}

} // namespace lambdaq::qubit