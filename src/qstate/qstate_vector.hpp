#ifndef QSVECTOR_HPP
#define QSVECTOR_HPP

#include <cstddef>
#include <vector>
#include <string>
#include <array>
#include <stdexcept>
#include <complex>

#include <Eigen/Dense>

#include "qstate.hpp"

namespace lambdaq::qstate {

template <std::size_t N>
class QStateVector : public QState<N> {
public:
    QStateVector() : qubits(Eigen::Matrix<std::complex<float>, (1 << N), 1>::Zero()) {}

    QStateVector(const Eigen::Matrix<std::complex<float>, (1 << N), 1>& qubits) : qubits(qubits) {
        if (qubits.norm() == 0) {
            throw std::invalid_argument("Qubit state cannot be zero.");
        }
    }

    virtual std::shared_ptr<Qubit> operator[](std::size_t index) override {
        throw std::logic_error("Not implemented: Qubit access in QStateVector");
    }
    
    virtual std::array<bool, N> collapse() override {
        std::array<bool, N> collapsed_states{};
        for (std::size_t i = 0; i < N; ++i) {
            collapsed_states[i] = false; // Placeholder: actual collapse logic depends on the quantum state
        }
        return collapsed_states;
    }

    virtual explicit operator std::string() const override {
        return "QStateVector";
    }

private:
    Eigen::Matrix<std::complex<float>, (1 << N), 1> qubits;
};

} // namespace lambdaq::qstate

#endif // QSVECTOR_HPP
