#include "tag.h"

int main() {
    auto p = P{
        IMG{"http://pokemon.com/pikachu.png"}
    };

    cout << p << endl;
    return 0;
}
