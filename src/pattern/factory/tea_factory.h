#pragma once

#include "hot_drink_factory.h"

struct TeaFactory : HotDrinkFactory {
    [[nodiscard]] unique_ptr<HotDrink> make() const override {
        return make_unique<Tea>();
    }
};