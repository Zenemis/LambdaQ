#ifndef QSIMPLE_HPP
#define QSIMPLE_HPP

#include <cstddef>
#include <string>
#include <array>
#include <stdexcept>

#include "qstate.hpp"
#include "qubit.hpp"
#include "qubit/qubit_coeffs.hpp"

namespace lambdaq::qstate {

template <std::size_t N>
class QStateSimple : public QState<N> {
public:
    QStateSimple() : qubits{} {}

    virtual std::shared_ptr<Qubit> operator[](std::size_t index) override {
        if (index >= N) throw std::out_of_range("Qubit index out of range");
        return std::shared_ptr<Qubit>(&qubits[index], [](Qubit*){/* no-op deleter */});
    }
    
    virtual std::array<bool, N> collapse() override {
        std::array<bool, N> collapsed_states{};
        for (std::size_t i = 0; i < N; ++i) {
            collapsed_states[i] = qubits[i].collapse();
        }
        return collapsed_states;
    }

    virtual explicit operator std::string() const override {
        return "QStateSimple";
    }

private:
    std::array<lambdaq::qubit::QubitCoeffs, N> qubits;
};

} // namespace lambdaq::qstate

#endif // QSIMPLE_HPP
