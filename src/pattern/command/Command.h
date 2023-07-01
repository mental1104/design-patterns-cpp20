#include "BankAccount.h"
#include <vector>
#include <initializer_list>

using std::vector;
using std::initializer_list;

struct Command
{
    bool withdrawal_succeeded;
    virtual void call() = 0;
    virtual void undo() = 0;
};

struct BankAccountCommand : Command
{
    
    BankAccount& account;
    enum Action { deposit, withdraw } action;
    int amount;

    BankAccountCommand(BankAccount& account, const Action action,
                       const int amount)
                       : account(account), action(action), amount(amount) {}

    void call() override
    {
        switch(action)
        {
        case deposit:
            account.deposit(amount);
            break;
        case withdraw:
            withdrawal_succeeded = account.withdraw(amount);
            break;
        }
    }

    void undo() override
    {
        switch(action)
        {
        case withdraw:
            if(withdrawal_succeeded)
                account.deposit(amount);
            break;
        case deposit:
            account.withdraw(amount);
            break;
        }
    }
};

struct CompositeBankAccountCommand :
vector<BankAccountCommand>, Command
{
    CompositeBankAccountCommand(const initializer_list<value_type>& items)
        : vector<BankAccountCommand>(items){}
    
    void call() override
    {
        for(auto& cmd : *this)
            cmd.call();
    }

    void undo() override
    {
        for(auto it = rbegin(); it != rend(); ++it)
            it->undo();
    }
};

struct MoneyTransferCommand : CompositeBankAccountCommand
{
    MoneyTransferCommand(BankAccount& from, BankAccount& to, int amount):
        CompositeBankAccountCommand
        {
            BankAccountCommand{from, BankAccountCommand::withdraw, amount},
            BankAccountCommand{to,   BankAccountCommand::deposit,  amount}
        } {}

    void call() override
    {
        bool ok = true;
        for(auto& cmd : *this)
        {
            if(ok)
            {
                cmd.call();
                ok = cmd.withdrawal_succeeded;
            }
            else
            {
                cmd.withdrawal_succeeded = false;
            }
        }
    }
};