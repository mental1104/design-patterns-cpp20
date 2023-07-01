#include "employee_factory.h"

int main() {
    auto john = EmployeeFactory::NewAuxOfficeEmployee("John Doe", 123);
    auto jane = EmployeeFactory::NewMainOfficeEmployee("Jane Doe", 125);

    cout << *john << endl;
    cout << *jane << endl;

    return 0;
}