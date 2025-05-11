#ifndef QGATE_CLASS_HPP
#define QGATE_CLASS_HPP

class QGate {
public:
    virtual ~QGate() = default;
};

QGate operator*(const QGate& lhs, const QGate& rhs);


#endif // QGATE_CLASS_HPP