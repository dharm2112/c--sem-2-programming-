//This program made by 24CE030.
/*1.1 Bank Account Management System
This system manages customer accounts by allowing deposits, withdrawals (with balance checks), and balance inquiries.
 It securely stores the account holder’s name, unique account number, and balance. 
 Object-oriented principles like encapsulation and methods are used for secure access.*/
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
        cout << "Enter your account number: ";
        cin >> number;
        cout << "Enter your bank balance: ";
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
            cout << "\nInsufficient balance. .";
        }
    }
    void display_balance()
     {
        cout << "Balance = " << balance << endl;
        cout << "\n ------------------------"<< endl;
    }
};

int main()
 {
    int n;
    cout << "Enter the number of accounts to create: ";
    cin >> n;
    
    BankAccount accounts[n];
    
    for (int i=0; i<n;i++)
     {
        cout << "\nEnter details for account " << i+1 << ":";
        accounts[i].getdata();
    }
    
    for (int i=0; i<n;i++) 
    {
        int amount1, amount2;
        cout << "\nAccount " << i+1 << " transactions:";
        cout << "\nEnter amount to deposit: ";
        cin >> amount1;
        accounts[i].deposit(amount1);
        
        cout << "Enter amount to withdraw: ";
        cin >> amount2;
        accounts[i].withdraw(amount2);
        
        accounts[i].display_balance();
    }
    cout << "this program made by 24CE030 - DHARM ." << endl;
    return 0;
}
