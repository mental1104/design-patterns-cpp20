#include <iostream>
#include <memory>
#include <map>
#include "hot_drink.h"
#include "drink_factory.h"

using namespace std;

unique_ptr<HotDrink> make_drink(const string& type) {
    unique_ptr<HotDrink> drink;
    if (type == "tea") {
        drink = make_unique<Tea>();
        drink->prepare(200);
    } else {
        drink = make_unique<Coffee>();
        drink->prepare(50);
    }
    return drink;
}

int main() {
    auto d = make_drink("tea");

    DrinkFactory df;
    df.make_drink("coffee");

    getchar();
    return 0;
}