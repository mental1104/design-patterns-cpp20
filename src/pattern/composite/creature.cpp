#include <array>
#include <algorithm>
#include <numeric>
#include <iostream>

using namespace std;

class Creature {
    enum Abilities {
        str, agl, intl, count
    };
    array<int, count> abilities;
public:
    int get_strength() const {
        return abilities[str];
    }

    void set_strength(int strength) {
        abilities[str] = strength;
    }

    int get_agility() const {
        return abilities[agl];
    }

    void set_agility(int agility) {
        abilities[agl] = agility;
    }

    int get_intelligence() const {
        return abilities[intl];
    }

    void set_intelligence(int intelligence) {
        abilities[intl] = intelligence;
    }

    int sum() const {
        return accumulate(abilities.begin(), abilities.end(), 0);
    }

    double average() const {
        return sum() / (double) count;
    }

    int max() const {
        return *max_element(abilities.begin(), abilities.end());
    }
};

int main(){
    Creature monster;
    monster.set_agility(50);
    monster.set_intelligence(100);
    monster.set_strength(10);
    std::cout << monster.sum() << std::endl;
    std::cout << monster.average() << std::endl;
    std::cout << monster.max() << std::endl;
    return 0;
}