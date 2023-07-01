#include <iostream>
#include "signal.h"
using namespace::std;

int main(){
    Person p{123};
    auto conn = p.property_changed.connect(
        [&](Person&, const string& prop_name)
        {
            cout << prop_name << " has been changed to " << p.get_age() << endl;
        }
    );
    p.set_age(20);
    p.set_age(100);
    conn.disconnect();
    return 0;
}