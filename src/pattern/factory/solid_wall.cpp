#include "solid_wall.h"
#include <iostream>
using std::cout;

int main(){
    const auto main_wall = SolidWall::create_main({0,0}, {0,3000}, 2700, 3000);
    cout << main_wall << "\n";
}