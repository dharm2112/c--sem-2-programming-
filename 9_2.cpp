#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

using namespace std;

class BankAccount {
private:
    string account_holder;
    double balance;
    vector<string> transaction_log;

public:
    BankAccount(string holder, double initial_balance)
        : account_holder(holder), balance(initial_balance) {}

    void deposit(double amount) {
        if (amount <= 0) {
            throw invalid_argument("Deposit amount must be positive.");
        }
        balance += amount;
        transaction_log.push_back("Deposited: " + to_string(amount));
        cout << "Deposited " << amount << ". New balance: " << balance << "\n";
    }

    void withdraw(double amount) {
        if (amount <= 0) {
            throw invalid_argument("Withdrawal amount must be positive.");
        }
        if (amount > balance) {
            throw runtime_error("Insufficient funds for withdrawal.");
        }
        balance -= amount;
        transaction_log.push_back("Withdrew: " + to_string(amount));
        cout << "Withdrew " << amount << ". New balance: " << balance << "\n";
    }

    void show_balance() const {
        cout << "Current balance: " << balance << "\n";
    }

    void show_transactions() const {
        cout << "Transaction history:\n";
        for (const auto& transaction : transaction_log) {
            cout << transaction << "\n";
        }
    }
};

int main() {
    BankAccount account("John Doe", 1000.0);

    int choice;
    double amount;

    while (true) {
        cout << "\n1. Deposit\n2. Withdraw\n3. Show Balance\n4. Show Transactions\n5. Exit\nEnter choice: ";
        cin >> choice;

        try {
            switch (choice) {
                case 1:
                    cout << "Enter deposit amount: ";
                    cin >> amount;
                    account.deposit(amount);
                    break;

                case 2:
                    cout << "Enter withdrawal amount: ";
                    cin >> amount;
                    account.withdraw(amount);
                    break;

                case 3:
                    account.show_balance();
                    break;

                case 4:
                    account.show_transactions();
                    break;

                case 5:
                    cout << "Exiting the system.\n";
                    return 0;

                default:
                    cout << "Invalid choice. Please try again.\n";
            }
        }
        catch (const invalid_argument& e) {
            cout << "Error: " << e.what() << "\n";
        }
        catch (const runtime_error& e) {
            cout << "Error: " << e.what() << "\n";
        }
        catch (...) {
            cout << "Unknown error occurred.\n";
        }
    }

    cout << "\nThis program is made by 24CE030 - DHARM." << endl;
    return 0;
}
