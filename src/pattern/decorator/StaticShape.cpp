#include <iostream>
#include "StaticShape.h"

using namespace::std;

int main(){

    {
        ColoredShape<TransparentShape<Square>> square{"red", 51, 5};
        cout << square.str() << endl;
    }
    
    return 0;
}