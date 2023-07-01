#include <iostream>
#include "value.h"

using namespace::std;

int main(){
    {
        const Const<int> life{42};
        cout << life/2 << "\n"; // 21
    }
    
    {
        OneOf<int> stuff{1, 3, 5};
        cout << stuff << "\n"; // will print 1, 3 or 5
    }
}