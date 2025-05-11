#ifndef QSTATE_HPP
#define QSTATE_HPP

#include <memory>

#include <cstddef>
#include <vector>
#include <string>

#include "qubit.hpp"

namespace lambdaq {

class QState {
public:
    virtual ~QState() = default;

    virtual Qubit& operator[](std::size_t index) = 0;
    
    virtual std::vector<bool> collapse() = 0;

    virtual explicit operator std::string() const {
        return "QState";
    }
};

namespace qstate {

std::shared_ptr<const QState> createQStateVector(std::size_t num_qubits);

} // namespace qstate

} // namespace lambdaq

#endif // QSTATE_HPP
