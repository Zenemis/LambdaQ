#ifndef QGATE_FUNC_HPP
#define QGATE_FUNC_HPP

#include <memory>
#include <qstate.hpp>

#include <qgate/qgate_class.hpp>
#include <qgate/qgate_vector.hpp>

namespace lambdaq::qgate::func {

template <std::size_t N>
std::shared_ptr<lambdaq::Qubit> x(std::shared_ptr<const lambdaq::Qubit> qubit) {
    // Pauli-X matrix
    static const Eigen::Matrix<std::complex<double>, 2, 2> X = []{
        Eigen::Matrix<std::complex<double>, 2, 2> m;
        m << 0, 1,
             1, 0;
        return m;
    }();

    lambdaq::qgate::QGateVector x_gate(X);
    auto result_qubit = x_gate.applyGate(*qubit);
    return std::static_pointer_cast<lambdaq::Qubit>(result_qubit);
}

template <std::size_t N>
std::shared_ptr<lambdaq::Qubit> y(std::shared_ptr<const lambdaq::Qubit> qubit) {
    // Pauli-Y matrix
    static const Eigen::Matrix<std::complex<double>, 2, 2> Y = []{
        Eigen::Matrix<std::complex<double>, 2, 2> m;
        m << 0, std::complex<double>(0, -1),
             std::complex<double>(0, 1), 0;
        return m;
    }();

    lambdaq::qgate::QGateVector y_gate(Y);
    auto result_qubit = y_gate.applyGate(*qubit);
    return std::static_pointer_cast<lambdaq::Qubit>(result_qubit);
}

template <std::size_t N>
std::shared_ptr<lambdaq::Qubit> z(std::shared_ptr<const lambdaq::Qubit> qubit) {
    // Pauli-Z matrix
    static const Eigen::Matrix<std::complex<double>, 2, 2> Z = []{
        Eigen::Matrix<std::complex<double>, 2, 2> m;
        m << 1, 0,
             0, -1;
        return m;
    }();

    lambdaq::qgate::QGateVector z_gate(Z);
    auto result_qubit = z_gate.applyGate(*qubit);
    return std::static_pointer_cast<lambdaq::Qubit>(result_qubit);
}

template <std::size_t N>
std::shared_ptr<lambdaq::Qubit> h(std::shared_ptr<const lambdaq::Qubit> qubit) {
    // Hadamard matrix
    static const Eigen::Matrix<std::complex<double>, 2, 2> H = []{
        Eigen::Matrix<std::complex<double>, 2, 2> m;
        m << 1, 1,
             1, -1;
        m /= std::sqrt(2.0);
        return m;
    }();

    lambdaq::qgate::QGateVector h_gate(H);
    auto result_qubit = h_gate.applyGate(*qubit);
    return std::static_pointer_cast<lambdaq::Qubit>(result_qubit);
}

template <std::size_t N>
std::shared_ptr<lambdaq::Qubit> s(std::shared_ptr<const lambdaq::Qubit> qubit) {
    // S (phase) gate
    static const Eigen::Matrix<std::complex<double>, 2, 2> S = []{
        Eigen::Matrix<std::complex<double>, 2, 2> m;
        m << 1, 0,
             0, std::complex<double>(0, 1);
        return m;
    }();

    lambdaq::qgate::QGateVector s_gate(S);
    auto result_qubit = s_gate.applyGate(*qubit);
    return std::static_pointer_cast<lambdaq::Qubit>(result_qubit);
}

template <std::size_t N>
std::shared_ptr<lambdaq::Qubit> t(std::shared_ptr<const lambdaq::Qubit> qubit) {
    // T (pi/8) gate
    static const Eigen::Matrix<std::complex<double>, 2, 2> T = []{
        Eigen::Matrix<std::complex<double>, 2, 2> m;
        m << 1, 0,
             0, std::exp(std::complex<double>(0, M_PI / 4));
        return m;
    }();

    lambdaq::qgate::QGateVector t_gate(T);
    auto result_qubit = t_gate.applyGate(*qubit);
    return std::static_pointer_cast<lambdaq::Qubit>(result_qubit);
}

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