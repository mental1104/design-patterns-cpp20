#include <string>
#include <boost/flyweight.hpp>
#include <iostream>

using std::string;
using boost::flyweight;
using std::cout;
using std::endl;
using std::boolalpha;

struct User2
{
    flyweight<string> first_name, last_name;

    User2(const string& first_name, const string& last_name)
        : first_name{first_name},
          last_name{last_name} {} 
};

int main(){
    User2 john_doe{"John", "Doe"};
    User2 jane_doe{"Jane", "Doe"};
    cout << boolalpha << (&jane_doe.last_name.get() == &john_doe.last_name.get()) << endl;
    return 0;
}