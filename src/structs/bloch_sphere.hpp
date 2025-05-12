#ifndef BLOCH_SPHERE_H
#define BLOCH_SPHERE_H

namespace lambdaq::structs {

class BlochSphere {
public:
    virtual ~BlochSphere() = default;

    virtual BlochSphere* clone() const = 0;

    virtual double getX() const = 0;
    virtual double getY() const = 0;
    virtual double getZ() const = 0;

    virtual double getTheta() const = 0;
    virtual double getPhi() const = 0;
};

} // namespace lambdaq::structs

#endif // BLOCH_SPHERE_H