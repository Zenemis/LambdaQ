#ifndef QSCOMP_HPP
#define QSCOMP_HPP

#include <cstddef>
#include <array>
#include <string>

#include <Eigen/Dense>

#include "qstate.hpp"

namespace lambdaq::qstate {

template <std::size_t N>
class QStateComposite : public QState<N> {
public:
    QStateComposite();

    virtual Qubit& operator[](std::size_t index) override;
    
    virtual std::array<bool, N> collapse() override;

    virtual explicit operator std::string() const override {
        return "QStateVector";
    }

private:
    std::array<float, N> qubits;
};

} // namespace lambdaq::qstate

#endif // QSCOMP_HPP
