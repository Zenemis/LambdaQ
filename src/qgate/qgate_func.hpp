#ifndef QGATE_FUNC_HPP
#define QGATE_FUNC_HPP

#include <memory>
#include "qstate.hpp"

namespace func {

std::shared_ptr<lambdaq::QState> x(std::shared_ptr<const lambdaq::QState> qstate);
std::shared_ptr<lambdaq::QState> y(std::shared_ptr<const lambdaq::QState> qstate);
std::shared_ptr<lambdaq::QState> z(std::shared_ptr<const lambdaq::QState> qstate);
std::shared_ptr<lambdaq::QState> h(std::shared_ptr<const lambdaq::QState> qstate);
std::shared_ptr<lambdaq::QState> s(std::shared_ptr<const lambdaq::QState> qstate);
std::shared_ptr<lambdaq::QState> t(std::shared_ptr<const lambdaq::QState> qstate);

} // namespace func

#endif // QGATE_FUNC_HPP