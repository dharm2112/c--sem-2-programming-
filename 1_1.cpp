//This program made by 24CE030.
#include <iostream>
using namespace std;

class BankAccount
 {
    char name[15];
    int number;
    float balance;

public:
    void getdata()
     {
        cout << "\nEnter your name: ";
        cin >> name;
        cout << "\nEnter your account number: ";
        cin >> number;
        cout << "\nEnter your bank balance: ";
        cin >> balance;
    }

    void deposit(int amount) {
        balance += amount;
    }

    void withdraw(int amount) {
        if (balance - amount >= 3000) {
            balance -= amount;
            cout << "\nCongratulations, you have withdrawn " << amount << ".";
        } else {
            cout << "\nInsufficient balance. Minimum balance of 3000 must be maintained.";
        }
    }

    void display_balance()
     {
        cout << "\nBalance = " << balance << endl;
        cout << "\n ------------------------\nthis program made by 24CE030 - DHARM .";
    }
};

int main()
 {
    int numAccounts;
    cout << "Enter the number of accounts to create: ";
    cin >> numAccounts;
    
    BankAccount accounts[numAccounts];
    
    for (int i=0; i<numAccounts;i++)
     {
        cout << "\nEnter details for account " << i+1 << ":";
        accounts[i].getdata();
    }
    
    for (int i=0; i<numAccounts;i++) 
    {
        int amount1, amount2;
        cout << "\nAccount " << i+1 << " transactions:";
        cout << "\nEnter amount to deposit: ";
        cin >> amount1;
        accounts[i].deposit(amount1);
        
        cout << "\nEnter amount to withdraw: ";
        cin >> amount2;
        accounts[i].withdraw(amount2);
        
        accounts[i].display_balance();
    }
    
    return 0;
}
