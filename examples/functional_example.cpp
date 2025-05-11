#include <iostream>
#include <memory>
#include <vector>

#include "qstate.hpp"
#include "qgate.h"

using lambdaq::QState;

using ConstQStatePtr = std::shared_ptr<const QState>;
using QStatePtr = std::shared_ptr<QState>;

int main(int argc, char** argv) {
    (void)argc;
    (void)argv;
    ConstQStatePtr qstate = lambdaq::qstate::createQStateVector(2); // Create a quantum state with 2 qubits
    
    printf("Initial state: %s\n", static_cast<std::string>(*qstate).c_str());

    // Apply some quantum gates
    QStatePtr psi1 = lambdaq::qgate::func::x(qstate); 

    printf("psi1: %s\n", static_cast<std::string>(*psi1).c_str());

    QStatePtr psi2 = lambdaq::qgate::func::y(psi1);

    printf("psi2: %s\n", static_cast<std::string>(*psi2).c_str());

    QStatePtr psi3 = lambdaq::qgate::func::z(psi2);

    printf("psi3: %s\n", static_cast<std::string>(*psi3).c_str());

    std::vector<bool> result = psi3->collapse(); // Collapse the state and get the result of the first qubit

    printf("Result of the first qubit: %d\n", (bool)result[0]);
    printf("Result of the second qubit: %d\n", (bool)result[1]);
}