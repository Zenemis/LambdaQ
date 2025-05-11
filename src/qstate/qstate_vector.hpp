#ifndef QSVECTOR_HPP
#define QSVECTOR_HPP

#include <cstddef>
#include <vector>
#include <string>


#include "qstate.hpp"

namespace lambdaq::qstate {

class QStateVector : public QState {
public:
    QStateVector(std::size_t num_qubits);

    virtual Qubit& operator[](std::size_t index) override;
    
    virtual std::vector<bool> collapse() override;

    virtual explicit operator std::string() const override {
        return "QStateVector";
    }

private:
    std::vector<float> qubits;

};

} // namespace lambdaq::qstate

#endif // QSVECTOR_HPP
