#include <memory>

#include "qstate.hpp"

#include "qstate/qstate_vector.hpp"

namespace lambdaq::qstate {

std::shared_ptr<const QState> createQStateVector(std::size_t num_qubits) {
    return std::make_shared<const QStateVector>(num_qubits);
}


} // namespace lambdaq::qstate