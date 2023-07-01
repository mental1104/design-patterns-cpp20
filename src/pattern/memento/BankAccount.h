#include <ostream>
#include <vector>
#include <memory>

using std::ostream;
using std::vector;
using std::shared_ptr;
using std::make_shared;

class Memento final
{
    int balance;
public:
    Memento(int balance)
        : balance(balance) {}
    int get_balance() { return balance; }
    friend class BankAccount;
};

class BankAccount
{
    int balance = 0;
public:
    explicit BankAccount(const int balance)
        : balance(balance) {}
    Memento deposit(int amount)
    {
        balance += amount;
        return { balance };
    }

    void restore(const Memento& m)
    {
        balance = m.balance;
    }

    friend ostream& operator<<(ostream& os, BankAccount& account){
        return os << "Balance: " << account.balance;
    }
};

class BankAccount2 {
    int balance = 0;
    vector<shared_ptr<Memento>> changes;
    int current;
public:
    explicit BankAccount2(const int balance) : balance(balance)
    {
        changes.emplace_back(make_shared<Memento>(balance));
        current = 0;
    }

    friend ostream& operator<<(ostream& os, BankAccount2& account){
        return os << "Balance: " << account.balance;
    }

    shared_ptr<Memento> deposit(int amount)
    {
        balance += amount;
        auto m = make_shared<Memento>(balance);
        changes.push_back(m);
        ++current;
        return m;
    }

    void restore(const shared_ptr<Memento>& m)
    {
        if(m)
        {
            balance = m->get_balance();
            changes.push_back(m);
            current = changes.size() - 1;
        }
    }

    shared_ptr<Memento> undo()
    {
        if(current > 0)
        {
            --current;
            auto m = changes[current];
            balance = m->get_balance();
            return m;
        }
        return {};
    }

    shared_ptr<Memento> redo()
    {
        if(current + 1 < changes.size())
        {
            ++current;
            auto m = changes[current];
            balance = m->get_balance();
            return m;
        }
        return {};
    }
};