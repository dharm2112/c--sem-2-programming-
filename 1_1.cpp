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
        cout << "Enter your name: ";
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
            cout << "\nInsufficient balance. ";
        }
    }
    void display_balance()
     {
        cout << "Balance = " << balance << endl;
        cout << " ------------------------"<< endl;
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
        cout << "\nEnter details for account " << i+1 << ":"<< endl;
        accounts[i].getdata();
    }
    
    for (int i=0; i<n;i++) 
    {
        int amount1, amount2;
        cout << "\nAccount " << i+1 << " transactions:" << endl;
        cout << "Enter amount to deposit: ";
        cin >> amount1;
        accounts[i].deposit(amount1);
        
        cout << "Enter amount to withdraw: ";
        cin >> amount2;
        accounts[i].withdraw(amount2);
        
        accounts[i].display_balance();
    }  
    cout << "this program made by 24CE030 - DHARM .";
    return 0;
}
