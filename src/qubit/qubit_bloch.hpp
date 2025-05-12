#ifndef QUBIT_BLOCH_HPP
#define QUBIT_BLOCH_HPP

#include <qubit.hpp>

#include <memory>
#include <complex>
#include <structs/bloch_sphere.hpp>

namespace lambdaq::qubit {

class QubitBloch : public lambdaq::Qubit {

public:
    QubitBloch(std::unique_ptr<lambdaq::structs::BlochSphere> bloch_sphere);
    QubitBloch(double theta, double phi);
    QubitBloch(double x, double y, double z);
    virtual ~QubitBloch() = default;

    virtual bool collapse() override;

    virtual double getProbability() const override;

    virtual std::complex<double> getZeroCoeff() const override;

    virtual std::complex<double> getOneCoeff() const override;

    virtual double getPhase() const override;

    virtual const std::shared_ptr<lambdaq::structs::BlochSphere> getBlochSphere() const override;

private:
    std::unique_ptr<lambdaq::structs::BlochSphere> bloch_sphere;

};
} // namespace lambdaq

#endif // QUBIT_BLOCH_HPP