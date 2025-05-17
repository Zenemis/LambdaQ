#ifndef BSPHERE_COORDS_H
#define BSPHERE_COORDS_H

#include <array>
#include <cmath>
#include <stdexcept>

#include <structs/bloch_sphere.hpp>

namespace lambdaq::structs::bsphere {

class BSphereCoords : public lambdaq::structs::BlochSphere {
public:
    BSphereCoords(double x, double y, double z)
        : x(x), y(y), z(z) {
        double r = std::sqrt(x * x + y * y + z * z);
        if (std::abs(r - 1.0) > 1e-6) {
            throw std::invalid_argument("The radius of the sphere must be 1.");
        }
    }

    virtual ~BSphereCoords() = default;

    virtual BSphereCoords* clone() const override {
        return new BSphereCoords(*this);
    }

    virtual double getX() const override {
        return x;
    }

    virtual double getY() const override {
        return y;
    }

    virtual double getZ() const override {
        return z;
    }

    virtual double getTheta() const override {
        return std::acos(z);
    }

    virtual double getPhi() const override {
        return std::atan2(y, x);
    }

private:
    double x; // X coordinate
    double y; // Y coordinate
    double z; // Z coordinate
};

} // namespace lambdaq::structs::bsphere

#endif // BSPHERE_COORDS_H