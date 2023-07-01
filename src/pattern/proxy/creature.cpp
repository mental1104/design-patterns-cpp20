#include "iostream"
#include "property.h"

using namespace::std;

struct Creature
{
    Property<int> strength{10};
    Property<int> agility{5};
};

int main(){
    Creature creature;
    creature.agility = 20;      // calls Property<int>::operator=
    auto x = creature.strength; // calls Property<int>::operator T
    std::cout << "creature.agility:\t" << creature.agility << std::endl;
    std::cout << "creature.strength:\t" << x << std::endl;
    return 0;
}