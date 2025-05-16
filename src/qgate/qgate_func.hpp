#ifndef QGATE_FUNC_HPP
#define QGATE_FUNC_HPP

#include <memory>
#include "qstate.hpp"

namespace func {

template <std::size_t N>
std::shared_ptr<lambdaq::QState<N>> x(std::shared_ptr<const lambdaq::QState<N>> qstate, std::size_t qubit);

template <std::size_t N>
std::shared_ptr<lambdaq::QState<N>> y(std::shared_ptr<const lambdaq::QState<N>> qstate, std::size_t qubit);

template <std::size_t N>
std::shared_ptr<lambdaq::QState<N>> z(std::shared_ptr<const lambdaq::QState<N>> qstate, std::size_t qubit);

template <std::size_t N>
std::shared_ptr<lambdaq::QState<N>> h(std::shared_ptr<const lambdaq::QState<N>> qstate, std::size_t qubit);

template <std::size_t N>
std::shared_ptr<lambdaq::QState<N>> s(std::shared_ptr<const lambdaq::QState<N>> qstate, std::size_t qubit);

template <std::size_t N>
std::shared_ptr<lambdaq::QState<N>> t(std::shared_ptr<const lambdaq::QState<N>> qstate, std::size_t qubit);

} // namespace func

#endif // QGATE_FUNC_HPP