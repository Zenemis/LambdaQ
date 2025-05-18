#ifndef QUBIT_HPP
#define QUBIT_HPP

#include <complex>
#include <memory>

#include <structs/bloch_sphere.hpp>

namespace lambdaq {

class Qubit {
    
public:
    virtual ~Qubit() = default;

    virtual bool collapse() = 0;

    virtual double getProbability() const = 0;

    virtual std::complex<double> getZeroCoeff() const = 0;

    virtual std::complex<double> getOneCoeff() const = 0;

    virtual double getPhase() const = 0;

    virtual const std::shared_ptr<lambdaq::structs::BlochSphere> getBlochSphere() const = 0;
};

} // namespace lambdaq

#endif // QUBIT_HPP
