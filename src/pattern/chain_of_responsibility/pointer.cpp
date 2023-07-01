#include <iostream>
#include "pointer.h"

using namespace::std;

int main(){
    Creature goblin{"Goblin", 1, 1};
    CreatureModifier root{goblin};
    DoubleAttackModifier r1{goblin};

    DoubleAttackModifier r1_2{goblin};
    IncreaseDefenseModifier r2{goblin};

    root.add(&r1);
    root.add(&r1_2);
    root.add(&r2);

    root.handle();

    cout << goblin << endl;
}