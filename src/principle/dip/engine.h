#pragma once
#include <iostream>
using std::ostream;

struct Engine
{
    float volume;
    int horse_power;

    Engine():volume{5}, horse_power{4000}{}
    friend ostream& operator<< (ostream& os, const Engine& obj){
        return os  
            << "volume: " << obj.volume
            << " horse_power: " << obj.horse_power;
    }
};