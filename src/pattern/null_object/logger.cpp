#include "logger.h"

int main(){
    {
        std::shared_ptr<Logger> null_logger = std::make_shared<NullLogger>();
        BankAccount account{"primary account", 1000, null_logger};
        account.deposit(2000);
    }
    {
        BankAccount account{"primary account", 1000};
        account.deposit(2000);
    }
    {
        std::shared_ptr<Logger> console_logger = std::make_shared<ConsoleLogger>();
        BankAccount account{"primary account", 1000, console_logger};
        account.deposit(2000);
    }
}