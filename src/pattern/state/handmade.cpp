#include <map>
#include <vector>
#include <utility>
#include <iostream>
#include <string>
#include <cxxabi.h>
#include <cstring>
#include <typeinfo>

using std::string;
using std::vector;
using std::map;
using std::pair;
using std::cin;
using std::cout;
using std::endl;

template<typename T>
std::string enumToString(T enumValue) {
    const auto& typeInfo = typeid(T);
    const auto& enumName = typeInfo.name();
    const auto& enumValueName = std::to_string(static_cast<int>(enumValue));
    const auto& functionName = std::string("_ZN") + std::to_string(strlen(enumName)) + enumName + enumValueName;
    std::cout << functionName << std::endl;
    char* demangledName = abi::__cxa_demangle(functionName.c_str(), nullptr, nullptr, nullptr);
    std::string result;
    if (demangledName != nullptr) {
        result = std::string(demangledName);
        free(demangledName);
    }
    return result;
}

enum class State
{
    off_hook,
    connecting,
    connected,
    on_hold,
    on_hook
};

enum class Trigger
{
    call_dialed,
    hung_up,
    call_connected,
    placed_on_hold,
    left_message,
    stop_using_phone
};

map<State, vector<pair<Trigger, State>>> rules;

int main(){

    rules[State::off_hook] = {
        {Trigger::call_dialed, State::connecting},
        {Trigger::stop_using_phone, State::on_hook}
    };

    rules[State::connecting] = {
        {Trigger::hung_up, State::off_hook},
        {Trigger::call_connected, State::connected}
    };

    State currentState{State::off_hook};
    State exitState{State::on_hook};

    while(true){
        cout << "The phone is currently " << enumToString(currentState) << endl;
    select_trigger:
        cout << "Select a trigger:" << "\n";

        int i = 0;
        for(auto item : rules[currentState])
        {
            cout << i++ << ". " << enumToString(item.first) << "\n";
        }

        int input;
        cin >> input;
        if(input < 0 || (input+1) > rules[currentState].size())
        {
            cout << "Incorrect option. Please try again." << "\n";
            goto select_trigger;
        }

        currentState = rules[currentState][input].second;
        if(currentState == exitState) break;
    }
}