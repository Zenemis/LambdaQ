#ifndef QSVECTOR_HPP
#define QSVECTOR_HPP

#include <cstddef>
#include <vector>
#include <string>
#include <array>
#include <stdexcept>

#include <Eigen/Dense>

#include "qstate.hpp"

namespace lambdaq::qstate {

template <std::size_t N>
class QStateVector : public QState<N> {
public:
    QStateVector() : qubits(Eigen::Array<float, N, 1>::Zero()) {}

    virtual Qubit& operator[](std::size_t index) override {
        throw std::logic_error("Not implemented: Qubit access in QStateVector");
    }
    
    virtual std::array<bool, N> collapse() override {
        std::array<bool, N> collapsed_states{};
        for (std::size_t i = 0; i < N; ++i) {
            collapsed_states[i] = qubits(i) > 0.5f; // Example threshold
        }
        return collapsed_states;
    }

    virtual explicit operator std::string() const override {
        return "QStateVector";
    }

private:
    Eigen::Array<float, N, 1> qubits;
};

} // namespace lambdaq::qstate

#endif // QSVECTOR_HPP
