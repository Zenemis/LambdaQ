#include "qstate_vector.hpp"
#include <stdexcept>

namespace lambdaq::qstate {

QStateVector::QStateVector(std::size_t num_qubits) : qubits(num_qubits) {
    // Initialize the qubits in the state vector
    for (std::size_t i = 0; i < num_qubits; ++i) {
        qubits[i] = 0.0f; // Assuming Qubit has a default constructor
    }
}

Qubit& QStateVector::operator[](std::size_t index) {
    throw std::runtime_error("QStateVector::operator[] is not implemented");
}

std::vector<bool> QStateVector::collapse() {
    std::vector<bool> collapsed_states;
    for (auto& qubit : qubits) {
        collapsed_states.push_back(qubit > 0.5f); // Assuming a simple threshold for collapse
    }
    return collapsed_states;
}

} // namespace lambdaq::qstate
