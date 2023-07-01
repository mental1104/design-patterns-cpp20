#include <iostream>
#include "interpret.h"

using namespace::std;

int main(){
    string input{ "(13-4)-(12+1)" };
    auto tokens = lex(input);
    for(auto i : tokens){
        std::cout << i.text << std::endl;
    }
    auto parsed = parse(tokens);
    cout << input << " = " << parsed->eval() << endl;
    // prints "(13-4)-(12+1) = -4"
}