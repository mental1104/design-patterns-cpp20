#include <iostream>
#include "rectangle.h"
using namespace::std;

void process(Rectangle& r)
{
    int w = r.get_width();
    r.set_height(10);
    cout << "expected area = " << (w * 10)
         << ", got " << r.area() << endl;
}


int main(){
    Square s{5};
    process(s);
    return 0;
}