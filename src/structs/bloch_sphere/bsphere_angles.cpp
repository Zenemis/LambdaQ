#include <structs/bloch_sphere/bsphere_angles.hpp>

#include <cmath>

namespace lambdaq::structs::bsphere {

BSphereAngles::BSphereAngles(double theta, double phi)
    : theta(theta), phi(phi) {}

BSphereAngles* BSphereAngles::clone() const {
    return new BSphereAngles(*this);
}

double BSphereAngles::getX() const {
    return std::sin(theta) * std::cos(phi);
}

double BSphereAngles::getY() const {
    return std::sin(theta) * std::sin(phi);
}

double BSphereAngles::getZ() const {
    return std::cos(theta);
}

double BSphereAngles::getTheta() const {
    return theta;
}

double BSphereAngles::getPhi() const {
    return phi;
}

} // namespace lambdaq::structs::bsphere