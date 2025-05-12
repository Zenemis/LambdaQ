#ifndef BSPHERE_ANGLES_H
#define BSPHERE_ANGLES_H

#include <structs/bloch_sphere.hpp>

#include <array>

namespace lambdaq::structs::bsphere {

class BSphereAngles : public lambdaq::structs::BlochSphere {
public:
    BSphereAngles(double theta, double phi);
    virtual ~BSphereAngles() = default;

    virtual BSphereAngles* clone() const override;

    virtual double getX() const override;
    virtual double getY() const override;
    virtual double getZ() const override;

    virtual double getTheta() const override;
    virtual double getPhi() const override;

private:
    double theta; // Angle in the XY plane
    double phi;   // Angle in the Z direction
};

} // namespace lambdaq::bsphere

#endif // BSPHERE_ANGLES_H