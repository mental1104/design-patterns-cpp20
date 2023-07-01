#include "Logger.h"

double add(double a, double b) {
    cout << a << "+" << b << "=" << (a + b) << endl;
    return a + b;
}

void print(const string& str) {
    cout << str << endl;
}

int main() {

    {
        Logger([]() { cout << "Hello\n"; }, "HelloFunction")();   
    }

    {
        auto call = make_logger2([]() { cout << "Hello!" << endl; }, "HelloFunction");
        call();
    }
        
    {
        auto logged_add = make_logger3(add, "Add");
        auto result = logged_add(2, 3);
        cout << result << endl;
    }

    {
        auto logged_add = make_logger4(add);
        int result = logged_add(2, 3);
        cout << "Result: " << result << endl;

        auto logged_print = make_logger4(print);
        logged_print("Hello, world!");
    }
    return 0;
}