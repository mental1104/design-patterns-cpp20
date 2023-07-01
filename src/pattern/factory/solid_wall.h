#ifndef DESIGN_PATTERNS_CPP20_SOLIDWALL_H
#define DESIGN_PATTERNS_CPP20_SOLIDWALL_H

#pragma once
#include <ostream>

#include "wall.h"
#include "material.h"

class SolidWall : public Wall {
    int width;
    Material material;
public:
    SolidWall(const Point2D start, const Point2D end, const int elevation,
              const int height, const int width, const Material material);

    friend std::ostream &operator<<(std::ostream &os, const SolidWall &obj) {
        return os
                << static_cast<const Wall &>(obj)
                << " width: " << obj.width
                << " material: " << obj.material;
    }

    static SolidWall create_main(Point2D start, Point2D end, int elevation, int height) {
        return SolidWall{start, end, elevation, height, 275, Material::aerated_concrete};
    }
    static std::unique_ptr<SolidWall> create_partition(Point2D start, Point2D end, int elevation, int height) {
        return make_unique<SolidWall>(start, end, elevation, height, 120, Material::brick);
    }
};

SolidWall::SolidWall(const Point2D start, const Point2D end, const int elevation,
                     const int height, const int width,
                     const Material material)
        : Wall{start, end, elevation, height},
          width{width}, material{material} {
    if (elevation < 0 && material == Material::aerated_concrete)
        throw invalid_argument("elevation");

    if (width < 120 && material == Material::brick)
        throw invalid_argument("width");
}

#endif //DESIGN_PATTERNS_CPP20_SOLIDWALL_H