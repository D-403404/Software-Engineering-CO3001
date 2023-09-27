#include <iostream>
#include <iomanip>

class BankAccount {
private:
    int             accNo;
    std::string     holder;
    double          balance;

public:
    BankAccount(int no, std::string name, double init) : accNo(no), holder(name), balance(init) {}

    void    deposit(double money) { balance += money; }
    void    withdraw(double money) { balance -= money; }
    double  getBalance() { return balance; }
};

void depositMoney(BankAccount* acc) {
    double money;
    std::cout << "Please enter the amount: ";
    std::cin >> money;
    if (money < 0) {
        std::cout << "Entered invalid number! Please try again!\n";
        depositMoney(acc);
    }
    else {
        acc->deposit(money);
        std::cout << "Operation success! Deposited " << money << " to your account!";
    }
}

void withdrawMoney(BankAccount* acc) {
    double money;
    std::cout << "Please enter the amount: ";
    std::cin >> money;
    if (money < 0) {
        std::cout << "Entered invalid number! Please try again!\n";
        withdrawMoney(acc);
    }
    else if (money > acc->getBalance()) {
        std::cout << "Your account does not have sufficient balance! Please try again!\n";
        withdrawMoney(acc);
    }
    else {
        acc->withdraw(money);
        std::cout << "Operation success! Withdrew " << money << " from your account!";
    }
}

void checkBalance(BankAccount* acc) {
    std::cout << "Your balance is: " << acc->getBalance();
}

void simulation() {
    int no, choice;
    std::string name;
    double money;

    std::cout << "Welcome to XXX Bank!\nPlease enter your name, your account number, and the initial balance to initiate your account!\n";
    std::cout << std::setw(30) << "Your name: ";
    std::cin >> name;
    std::cout << std::setw(30) << "Your account number: ";
    std::cin >> no;
    std::cout << std::setw(30) << "The initial balance: ";
    std::cin >> money;

    BankAccount* newAccount = new BankAccount(no, name, money);

    while(1) {
        std::cout << "What would you like to do?\nPress -1 to quit.\nPress 1 to deposit money.\nPress 2 to withdraw money.\nPress 3 to check balance.\nYour choice: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            depositMoney(newAccount);
            break;
        case 2:
            withdrawMoney(newAccount);
            break;
        case 3:
            checkBalance(newAccount);
            break;
        case -1:
            delete newAccount;
            return;
        default:
            break;
        }
        std::cout << "\n\n";
    }
    
}

int main() {
    simulation();

    return 0;
}