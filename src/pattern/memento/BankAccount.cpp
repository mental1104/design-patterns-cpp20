#include <iostream>
#include "BankAccount.h"

using std::cout;

void memento()
{
    
    BankAccount ba{100};
    auto m1 = ba.deposit(50);
    auto m2 = ba.deposit(25);
    cout << ba << "\n"; // Balance: 175
    
    ba.restore(m1);
    cout << ba << "\n"; // Balance: 150

    ba.restore(m2);
    cout << ba << "\n"; // Balance: 175
}

void memento2()
{
    BankAccount2 ba{100};
    ba.deposit(50);
    ba.deposit(25);
    cout << ba << "\n";

    ba.undo();

    cout << "Undo 1: " << ba << "\n"; 
    ba.undo();

    cout << "Undo 2: " << ba << "\n";
    ba.redo();

    cout << "Redo 2: " << ba << "\n";
    ba.undo();

}

int main(){
    memento();
    memento2();
}