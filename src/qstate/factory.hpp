#ifndef QSTATE_FACTORY_HPP
#define QSTATE_FACTORY_HPP

#include <cstddef>
#include <memory>

#include "qstate.hpp"
#include "qstate_vector.hpp"
#include "qstate_simple.hpp"

namespace lambdaq::qstate {

template <std::size_t N>
std::shared_ptr<const lambdaq::QState<N>> createQStateSimple(){
    return std::static_pointer_cast<const lambdaq::QState<N>>(std::make_shared<lambdaq::qstate::QStateSimple<N>>());
}

template <std::size_t N>
std::shared_ptr<const lambdaq::QState<N>> createQStateVector(){
    return std::static_pointer_cast<const lambdaq::QState<N>>(std::make_shared<lambdaq::qstate::QStateVector<N>>());
}

} // namespace qstate

#endif // QSTATE_FACTORY_HPP