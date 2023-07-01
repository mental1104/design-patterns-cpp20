#include <string>
#include <vector>
#include <iostream>

#include "filter.h"
using namespace::std;


int main(){
    Product apple{"Apple", Color::Green, Size::Small, Feature::Less};
    Product tree{"Tree", Color::Green, Size::Large, Feature::More };
    Product house{"House", Color::Blue, Size::Large, Feature::More};

    vector<Product*> all {&apple, &tree, &house};

    BetterFilter bf;
    {
        
        auto green_things = bf.filter(all, ColorSpecification(Color::Green));
        for(auto& x : green_things)
            cout << x->name << " is green" << endl;
    }
    

    {
        SizeSpecification large(Size::Large);
        ColorSpecification green(Color::Green);
        AndSpecification<Product> green_and_large{large, green};

        auto big_green_things = bf.filter(all, std::move(green_and_large));
        for(auto& x : big_green_things){
            cout << x->name << " is large and green" << endl;
        }
    }

    {
        SizeSpecification large(Size::Large);
        FeatureSpecification more(Feature::More);

        auto more_large_things = bf.filter(all, large && more);
        for(auto& x : more_large_things){
            cout << x->name << " is large and has more feature" << endl;
        }
    }
    
    return 0;
}