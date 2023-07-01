#include <iostream>
#include <string>
#include <variant>
#include <type_traits>

using std::string;
using std::cout;
using std::visit;
using std::variant;
using std::decay_t;
using std::is_same_v;

struct AddressPrinter
{
    void operator()(const string& house_name) const {
        cout << "A house called " << house_name << "\n";
    }

    void operator()(const int house_number) const {
        cout << "House number " << house_number << "\n";
    }
};

int main(){
    variant<string, int> house;
    // house = "Montefiore Castle";
    house = 221;
    AddressPrinter ap;
    visit(ap, house); // House number 221

    visit([](auto& arg) {
        using T = decay_t<decltype(arg)>;
        if constexpr (is_same_v<T, string>)
        {
            cout << "A house called " << arg.c_str() << "\n";
        }
        else
        {
            cout << "House number " << arg << "\n";
        }
    }, house);
}