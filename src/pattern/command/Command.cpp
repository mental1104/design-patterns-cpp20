#include "Command.h"

int main(){
    {
        BankAccount ba;
        BankAccountCommand cmd{ba, BankAccountCommand::deposit, 100};
        cmd.call();
    }
    
    {
        BankAccount X;
        BankAccount Y;
        BankAccountCommand cmd1{X, BankAccountCommand::deposit, 100};
        cmd1.call();
        MoneyTransferCommand cmd2{X, Y, 30};
        cmd2.call();
        cmd2.undo();
    }
}