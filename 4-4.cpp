/*
4.4 Banking System
Manages bank accounts using a hierarchical class structure with savings and current account types.
Tracks transactions using a stack to enable undo functionality for deposits and withdrawals.
Uses constructors and destructors for proper object initialization and cleanup.
Supports essential banking operations like deposit, withdraw, and balance display.
Main Concept: Inheritance, constructor overloading, destructor usage, and stack-based transaction handling.
*/
#include<iostream>
#include<stack>
using namespace std;

struct Transaction {
    string type;    
    double amount;
};
class Bankaccount
{
    protected:
        int accnumber;
        double balance;

    public:
        Bankaccount() : accnumber(0), balance(0) {}

        Bankaccount(int num , double bal)
        {
            accnumber = num;
            balance = bal;
        }
        
        void deposit(int amt)
        {
            balance += amt;
            cout << balance << endl;
        }

        void withdraw(int amt)
        {
            if(amt < balance)
            {
                balance -= amt;
                cout << "withdraw amount : " << amt << "current balance : " << balance << endl;
            }
            else
                cout << "insufficient balance ." << endl;
        }

        void undo(stack<Transaction>& transactions) 
        {
            if (transactions.empty()) {
                cout << "No transaction to undo.\n";
                return;
            }
    
            Transaction last = transactions.top();
            transactions.pop();
    
            if (last.type == "deposit")
            {
                balance -= last.amount;
                cout << "Undo deposit of " << last.amount << ". New balance: " << balance << endl;
            }
             else if (last.type == "withdraw") 
             {
                balance += last.amount;
                cout << "Undo withdraw of " << last.amount << ". New balance: " << balance << endl;
            }
        }

        double dispalybalance()
        {
            return balance;
        }
};

class savingaccount : public Bankaccount
{
    public:
    savingaccount() : Bankaccount() {}

    savingaccount(int num , double bal) : Bankaccount(num,bal){}
};

class currentaccount : public Bankaccount
{
    double overdraft_limit;

    public:
        currentaccount() : Bankaccount(), overdraft_limit(0) {} 

        currentaccount(int num , double bal, double limit): Bankaccount(num,bal){
            overdraft_limit = limit;
        }
        
        
        void withdraw(double amt) {
            if (amt <= (balance + overdraft_limit))
            {
                balance -= amt;
                cout << "Withdrawn: " << amt << ", New Balance: " << balance << endl;
            } else {
                cout << "Overdraft limit exceeded." << endl;
            }
        }
};

int main()
{
    int n;
    int id;
    double bal;
        cout << "Enter account number: ";
        cin >> id;
        cout << "Enter initial balance: ";
        cin >> bal;
    cout <<  "1.saving account\n2.current account \nEnter your choice :" ;
    cin >> n;

    savingaccount sa;
    currentaccount ca;

    
    if (n == 1) 
    {
        sa = savingaccount(id, bal);
    }
     else if (n == 2) 
    {
        double limit;
        cout << "Enter overdraft limit: ";
        cin >> limit;
        ca = currentaccount(id, bal, limit);
    } 
    else 
    {
        cout << "Invalid account type.\n";
        return 1;
    }
    stack<Transaction> transactions;
    int opt;
    double amount;

    do {
        cout << "\n--- Banking Menu ---\n";
        cout << "1. Deposit\n2. Withdraw\n3. Show Balance\n4. Undo Last Transaction\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> opt;

        switch (opt) {
            case 1:
                cout << "Enter deposit amount: ";
                cin >> amount;
                if (n == 1) 
                sa.deposit(amount);
                else 
                ca.deposit(amount);

                transactions.push({"deposit", amount});
                break;

            case 2:
                cout << "Enter withdraw amount: ";
                cin >> amount;
                if (n == 1) 
                sa.withdraw(amount);
                else 
                ca.withdraw(amount);

                transactions.push({"withdraw", amount});
                break;

            case 3:
                if (n == 1) 
                cout << "Current balance: " << sa.dispalybalance() << endl;
                else 
                cout << "Current balance: " << ca.dispalybalance() << endl;
                break;

            case 4:
                if (n == 1)
                 sa.undo(transactions);
                else 
                ca.undo(transactions);
                break;

            case 5:
                cout << "Thank you! Exiting...\n";
                break;

            default:
                cout << "Invalid option. Try again.\n";
        }
    } while (opt != 5);
    cout << "This program is made by 24CE030 - DHARM." << endl;
   return 0; 
}