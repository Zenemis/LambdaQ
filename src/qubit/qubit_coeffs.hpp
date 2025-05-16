#ifndef QUBIT_COEFFS_HPP
#define QUBIT_COEFFS_HPP

#include <qubit.hpp>

#include <memory>
#include <complex>
#include <structs/bloch_sphere.hpp>

namespace lambdaq::qubit {

class QubitCoeffs : public lambdaq::Qubit {

public:
    QubitCoeffs();
    QubitCoeffs(std::complex<double> coeff_zero, std::complex<double> coeff_one);
    virtual ~QubitCoeffs() = default;

    virtual bool collapse() override;

    virtual double getProbability() const override;

    virtual std::complex<double> getZeroCoeff() const override;

    virtual std::complex<double> getOneCoeff() const override;

    virtual double getPhase() const override;

    virtual const std::shared_ptr<lambdaq::structs::BlochSphere> getBlochSphere() const override;

private:
    std::complex<double> coeff_zero; // Coefficient for |0> state
    std::complex<double> coeff_one;  // Coefficient for |1> state

};
} // namespace lambdaq

#endif // QUBIT_COEFFS_HPP