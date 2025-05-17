#ifndef BSPHERE_ANGLES_H
#define BSPHERE_ANGLES_H

#include <array>
#include <cmath>

#include <structs/bloch_sphere.hpp>

namespace lambdaq::structs::bsphere {

class BSphereAngles : public lambdaq::structs::BlochSphere {
public:
    BSphereAngles(double theta, double phi)
        : theta(theta), phi(phi) {}

    virtual ~BSphereAngles() = default;

    virtual BSphereAngles* clone() const override {
        return new BSphereAngles(*this);
    }

    virtual double getX() const override {
        return std::sin(theta) * std::cos(phi);
    }

    virtual double getY() const override {
        return std::sin(theta) * std::sin(phi);
    }

    virtual double getZ() const override {
        return std::cos(theta);
    }

    virtual double getTheta() const override {
        return theta;
    }

    virtual double getPhi() const override {
        return phi;
    }

private:
    double theta; // Angle in the XY plane
    double phi;   // Angle in the Z direction
};

} // namespace lambdaq::structs::bsphere

#endif // BSPHERE_ANGLES_H