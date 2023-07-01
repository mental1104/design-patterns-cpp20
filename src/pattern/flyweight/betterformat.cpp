#include <iostream>
#include "betterformat.h"

using namespace::std;

int main(){
    BetterFormattedText bft("This is a brave new world");
    bft.get_range(10, 15).capitalize = true;
    cout << bft << endl; // This is a BRAVE new world
}