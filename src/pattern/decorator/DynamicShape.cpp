#include <iostream>
#include "DynamicShape.h"
using namespace::std;

int main(){

    {
        Circle circle{0.5f};
        ColoredShape redCircle{circle, "red"};
        cout << redCircle.str() << endl;
        // A circle of radius 0.5 has the color red
        redCircle.make_dark();
        cout << redCircle.str() << endl;
        // A circle of radius 0.5 has the color dark red
    }

    {
        Square square{3};
        TransparentShape demiSquare{square, 85};
        cout << demiSquare.str() << endl;
        // A square with side 3 has 33.333% transparency
    }

    {
        Circle c{23};
        ColoredShape cs{c, "green"};
        TransparentShape myCircle{cs, 64};
        cout << myCircle.str() << endl;
        // A circle of radius 23 has the color green has 25.098% transparency
    }
    return 0;
}

