#ifndef QSTATE_HPP
#define QSTATE_HPP

#include <memory>
#include <cstddef>
#include <vector>
#include <string>
#include <array>

#include <qgate/qgate_class.hpp>

#include "qubit.hpp"

namespace lambdaq {

template <std::size_t N>
class QState {
public:
    virtual ~QState() = default;

    virtual std::shared_ptr<Qubit> operator[](std::size_t index) = 0;

    virtual std::array<bool, N> collapse() = 0;

    virtual explicit operator std::string() const {
        return "QState";
    }

    static constexpr std::size_t size = N;
};

} // namespace lambdaq

#endif // QSTATE_HPP
