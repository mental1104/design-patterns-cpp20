#include <iostream>
#include <string>

using std::ostream;
using std::string;

struct Creature
{
    string name;
    int attack, defense;

    Creature() = default;
    Creature(string name, int attack, int defense)
        :name{name}, attack{attack}, defense{defense} {}

    friend ostream& operator<< (ostream& os, Creature& rhs){
        return os << "Name: " << rhs.name << " " 
                  << "Attack: " << rhs.attack << " "
                  << "Defense: "<< rhs.defense;
    }
};

class CreatureModifier
{
    CreatureModifier* next{nullptr};
protected:
    Creature& creature;
public:
    explicit CreatureModifier(Creature& creature)
        : creature(creature) {}
    void add(CreatureModifier* cm)
    {
        if(next) next->add(cm);
        else next = cm;
    }

    virtual void handle()
    {
        if(next) next->handle();
    }
};

class DoubleAttackModifier : public CreatureModifier
{
public:
    explicit DoubleAttackModifier(Creature& creature)
        : CreatureModifier(creature) {}
    
    void handle() override
    {
        creature.attack *= 2;
        CreatureModifier::handle();
    }
};

class IncreaseDefenseModifier :public CreatureModifier
{
public:
    explicit IncreaseDefenseModifier(Creature& creature)
        : CreatureModifier(creature) {}
    
    void handle() override
    {
        if(creature.attack <= 2) creature.defense += 1;
        CreatureModifier::handle();
    }
};