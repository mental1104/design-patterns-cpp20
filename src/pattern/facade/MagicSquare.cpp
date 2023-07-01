#include <iostream>
#include "MagicSquare.h"

void print(const vector<vector<int>>& square) {
    for(auto i : square){
        for(auto j : i){
            std::cout << j << " ";
        }
        std::cout << std::endl;
    }
}

int main(){
    {
        MagicSquareGenerator<> gen;
        auto square = gen.generate(3);
        print(square);
    }
    std::cout << "------------------------" << std::endl;
    {
        MagicSquareGenerator<UniqueGenerator> gen;
        auto square = gen.generate(3);
        print(square);
    }
    return 0;
}