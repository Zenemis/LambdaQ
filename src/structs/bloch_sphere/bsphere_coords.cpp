#include "structs/bloch_sphere/bsphere_coords.hpp"
#include <cmath>

#include <stdexcept>

namespace lambdaq::structs::bsphere {

BSphereCoords::BSphereCoords(double x, double y, double z)
    : x(x), y(y), z(z) {
    double r = std::sqrt(x * x + y * y + z * z);
    if (std::abs(r - 1.0) > 1e-6) {
        throw std::invalid_argument("The radius of the sphere must be 1.");
    }
}

BSphereCoords* BSphereCoords::clone() const {
    return new BSphereCoords(*this);
}

double BSphereCoords::getX() const {
    return x;
}

double BSphereCoords::getY() const {
    return y;
}

double BSphereCoords::getZ() const {
    return z;
}

double BSphereCoords::getTheta() const {
    return std::acos(z);
}

double BSphereCoords::getPhi() const {
    return std::atan2(y, x);
}

} // namespace lambdaq::structs::bsphere