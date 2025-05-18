#ifndef QGATE_VECTOR_HPP
#define QGATE_VECTOR_HPP

#include <memory>
#include <complex>

#include <qgate.h>
#include <qubit.hpp>

#include <qubit/qubit_vector.hpp>
#include <Eigen/Dense>

namespace lambdaq::qgate {

class QGateVector : public lambdaq::QGate {
public:
    QGateVector(const Eigen::Matrix<std::complex<double>, 2, 2>& matrix)
        : matrix(matrix) {}

    virtual std::shared_ptr<lambdaq::Qubit> applyGate(const lambdaq::Qubit& qubit) const override {
        // Try to cast to QubitVector
        auto qv = dynamic_cast<const lambdaq::qubit::QubitVector*>(&qubit);
        if (!qv) throw std::invalid_argument("QGateVector can only be applied to QubitVector");

        Eigen::Matrix<std::complex<double>, 2, 1> new_state = matrix * qv->state;
        return std::make_shared<lambdaq::qubit::QubitVector>(new_state);
    }

private:
    Eigen::Matrix<std::complex<double>, 2, 2> matrix;
};

} // namespace lambdaq::qgate

#endif // QGATE_VECTOR_HPP