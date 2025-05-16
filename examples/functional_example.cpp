#include <iostream>
#include <memory>
#include <vector>

#include "qstate.hpp"
#include "qstate/factory.hpp"

#include "qgate.h"

using lambdaq::QState;

using ConstQStatePtr = std::shared_ptr<const QState<2>>;
using QStatePtr = std::shared_ptr<QState<2>>;

int main(int argc, char** argv) {
    (void)argc;
    (void)argv;
    ConstQStatePtr qstate = lambdaq::qstate::createQStateSimple<2>(); // Create a quantum state with 2 qubits
    
    printf("Initial state: %s\n", static_cast<std::string>(*qstate).c_str());

    // Apply some quantum gates
    QStatePtr psi1 = lambdaq::qgate::func::x(qstate, 0); // Apply X gate to the first qubit 

    printf("psi1: %s\n", static_cast<std::string>(*psi1).c_str());

    QStatePtr psi2 = lambdaq::qgate::func::y<2>(psi1, 1); // Apply Y gate to the second qubit

    printf("psi2: %s\n", static_cast<std::string>(*psi2).c_str());

    QStatePtr psi3 = lambdaq::qgate::func::z<2>(psi2, 0); // Apply Z gate to the first qubit

    printf("psi3: %s\n", static_cast<std::string>(*psi3).c_str());

    std::array<bool, 2> result = psi3->collapse(); // Collapse the state and get the result of the first qubit

    printf("Result of the first qubit: %d\n", (bool)result[0]);
    printf("Result of the second qubit: %d\n", (bool)result[1]);
}