#include <ostream>

#pragma once

enum class Material {
    brick,
    aerated_concrete,
    drywall
};

std::ostream &operator<<(std::ostream &os, Material material) {
    switch (material) {
        case Material::brick:
            return os << "brick";
        case Material::aerated_concrete:
            return os << "aerated concrete";
        case Material::drywall:
            return os << "drywall";
        default:
            return os;
    }
}