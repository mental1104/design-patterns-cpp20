#include "contact_copy.h"

int main() {
    Contact worker{"", new Address{"123 East Dr", "London", 0}};

    Contact john{worker};
    john.name = "John";
    john.address->suite = 10;

    cout << john << endl;

    return 0;
}