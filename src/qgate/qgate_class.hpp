#ifndef QGATE_CLASS_HPP
#define QGATE_CLASS_HPP

#include <memory>
#include <qubit.hpp>

namespace lambdaq {

class QGate {
public:
    virtual ~QGate() = default;
    
    virtual std::shared_ptr<lambdaq::Qubit> applyGate(const lambdaq::Qubit& qubit) const = 0;

    virtual std::shared_ptr<lambdaq::Qubit> operator()(const lambdaq::Qubit& qubit){
        return applyGate(qubit);
    }
};

std::shared_ptr<lambdaq::Qubit> operator*(const QGate& gate, const lambdaq::Qubit& qubit) {
    return gate.applyGate(qubit);
}

};

#endif // QGATE_CLASS_HPP0