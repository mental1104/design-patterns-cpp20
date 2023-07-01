#include "extended_address.h"

int main() {
    ExtendedAddress ea{"123 West Dr", "London", 123, "UK", "SW1010EG"};
    Address &a = ea;
    auto cloned = a.clone();
    cout << *cloned << endl;
}