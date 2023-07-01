#include "wall_factory.h"
#include <iostream>

int main() {
    const auto partition = WallFactory::create_partition(
        {2000, 0}, {2000, 4000}, 0, 2700);
    std::cout << *partition << "\n";

    const auto also_partition = 
    WallFactory::create_wall(WallType::partition, {0,0},
                            {5000,0}, 0, 4200);
    if (also_partition)
        cout << *dynamic_pointer_cast<SolidWall>(also_partition) << "\n";
}