#ifndef BSPHERE_COORDS_H
#define BSPHERE_COORDS_H

#include <structs/bloch_sphere.hpp>

#include <array>

namespace lambdaq::structs::bsphere {

class BSphereCoords : public lambdaq::structs::BlochSphere {
public:
    BSphereCoords(double x, double y, double z);
    virtual ~BSphereCoords() = default;

    virtual BSphereCoords* clone() const override;

    virtual double getX() const override;
    virtual double getY() const override;
    virtual double getZ() const override;

    virtual double getTheta() const override;
    virtual double getPhi() const override;

private:
    double x; // X coordinate
    double y; // Y coordinate
    double z; // Z coordinate
};

} // namespace lambdaq::bsphere

#endif // BSPHERE_COORDS_H