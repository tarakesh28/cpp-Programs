#include <iostream>
#include <stdexcept>
using namespace std;

class InsufficientFunds : public runtime_error {
public:
    InsufficientFunds() : runtime_error("Insufficient Balance!") {}
};

class BankAccount {
    float balance;

public:
    BankAccount(float b) {balance = b;}

    void withdraw(float amount) {
        if (amount > balance) throw InsufficientFunds();
        balance -= amount;
        cout << "Withdrawal Successful!" << endl;
        cout << "Remaining Balance: " << balance << endl;
    }
};

int main() {
    BankAccount account(5000);
    float amount;
    cout << "Enter withdrawal amount: ";
    cin >> amount;
    try {account.withdraw(amount);}
    catch (InsufficientFunds& e) {
        cout << "Exception: " << e.what() << endl;
    }
    return 0;
}