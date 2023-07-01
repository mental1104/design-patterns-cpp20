#include <string>
#include <memory>
#include <iostream>

using std::cout;
using std::endl;
using std::string;
using std::shared_ptr;
using std::make_shared;
using std::to_string;

struct Logger
{
    virtual ~Logger() = default;
    virtual void info(const string& s) = 0;
    virtual void warn(const string& s) = 0;
};

struct NullLogger final : Logger
{
    void info(const string& s) override {}
    void warn(const string& s) override {}
};

struct ConsoleLogger : Logger
{
    void info(const string& s) override
    {
        cout << "INFO: " << s << endl;
    }

    void warn(const string& s) override
    {
        cout << "WARNING!!! " << s << endl;
    }
};

struct OptionalLogger : Logger
{
    shared_ptr<Logger> impl;
    static shared_ptr<Logger> no_logging;
    
    OptionalLogger(const shared_ptr<Logger>& logger) : impl{logger} {}

    virtual void info(const string& s) override {
        if(impl) impl->info(s);
    }

    virtual void warn(const string& s) override {
        if(impl) impl->warn(s);
    }
};

shared_ptr<Logger> OptionalLogger::no_logging{};

class BankAccount
{
    shared_ptr<Logger> log;
public:
    string name;
    int balance = 0;

    BankAccount(const string& name,
                int balance,
                const shared_ptr<Logger>& logger = OptionalLogger::no_logging)
        : log{make_shared<OptionalLogger>(logger)}, name{name}, balance{balance} { }

    void deposit(int amount);
};

void BankAccount::deposit(int amount)
{
    balance += amount;
    log->info("Deposited $" + to_string(amount)
        + " to " + name + ", balance is now $" + to_string(balance));
}