#ifndef QUBIT_HPP
#define QUBIT_HPP

namespace lambdaq {

class Qubit {
public:
    virtual ~Qubit() = default;

    virtual bool collapse() = 0;
};

} // namespace lambdaq

#endif // QUBIT_HPP
