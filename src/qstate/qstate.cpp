#include <memory>

#include "qstate.hpp"

#include "qstate/qstate_vector.hpp"

namespace lambdaq::qstate {

template <std::size_t N>
std::shared_ptr<const QState<N>> createQStateVector() {
    return std::make_shared<const QStateVector<N>>();
}


} // namespace lambdaq::qstate