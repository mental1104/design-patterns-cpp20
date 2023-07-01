#include <iostream>
using std::cout;

struct BankAccount
{
    int balance = 0;
    int overdraft_limit = -500;

    void deposit(int amount)
    {
        balance += amount;
        cout << "deposited " << amount << ", balance is now " <<
                balance << "\n";
    }

    bool withdraw(int amount)
{
    if(balance - amount >= overdraft_limit)
    {
        balance -= amount;
        cout << "withdrew " << amount << ", balance now " << 
            balance << "\n";
        return true;
    }
    return false;
}
};


