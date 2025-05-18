#include <iostream>
#include <memory>
#include "qubit.hpp"
#include "qubit/qubit_vector.hpp"
#include "qgate/qgate_func.hpp"

using lambdaq::Qubit;
using QubitPtr = std::shared_ptr<Qubit>;

int main(int argc, char** argv) {
    (void)argc;
    (void)argv;

    // Start with a |0> qubit
    QubitPtr qubit = std::make_shared<lambdaq::qubit::QubitVector>();

    std::cout << "Initial |0> state: |0>=" << qubit->getZeroCoeff() << " |1>=" << qubit->getOneCoeff() << std::endl;

    // Apply X gate
    qubit = lambdaq::qgate::func::x<1>(qubit);
    std::cout << "After X: |0>=" << qubit->getZeroCoeff() << " |1>=" << qubit->getOneCoeff() << std::endl;

    // Apply Y gate
    qubit = lambdaq::qgate::func::y<1>(qubit);
    std::cout << "After Y: |0>=" << qubit->getZeroCoeff() << " |1>=" << qubit->getOneCoeff() << std::endl;

    // Apply Z gate
    qubit = lambdaq::qgate::func::z<1>(qubit);
    std::cout << "After Z: |0>=" << qubit->getZeroCoeff() << " |1>=" << qubit->getOneCoeff() << std::endl;

    // Collapse and print result
    bool result = qubit->collapse();
    std::cout << "Collapse result: " << result << std::endl;
}