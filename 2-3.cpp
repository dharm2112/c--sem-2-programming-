/*
2.3 Enhanced Bank Account System
Creates accounts with or without initial balance, supports deposits and withdrawals.
Checks for sufficient balance before withdrawal and shows account summary.
Applies encapsulation and constructor overloading in OOP.
*/
#include<iostream>
#include<string.h>
using namespace std;
class bankaccount
{
    char accountaunor[15];
    int accountno;
    double balance;

    public :
        bankaccount(){}
          //parameterized constructor
        bankaccount(char name [] , int number, double initialbalance)
        {
            strcpy(accountaunor,name);
            accountno = number;
            balance = initialbalance;
        }
        
        void deposit(double amount)
        {
            if(amount > 0)
            {
                balance += amount ;
                cout << "Deposit successful." << endl;
                cout << "New balance : " << balance ;
            }
            else
            {
                cout << "Invalid ."<< endl;
            }
        }

        void display()
        {
            cout << "\nAccount holder : " << accountaunor ;
            cout << "\nAccount number : " << accountno ;
            cout << "\nBalance : " << balance << endl;
        }
};
int main()
{
   
    char accountaunor[15];
    int accountno,t;
    double balance;
    double amount;

    cout << "Enter number of account :" ;
    cin >> t;
    bankaccount s[t];
for(int i=0;i<t;i++)
{
    cout << "\nEnter account holder name :";
    cin >> accountaunor;
    cout << "Enter account number :";
    cin >> accountno;
    cout << "Enter current balance :";
    cin >> balance ;
    cout << endl;

    s[i] = bankaccount(accountaunor,accountno ,balance );
}
for(int i=0;i<t;i++)
{
    cout << i+1 << ". Enter amount to deposit :";
    cin >> amount ;

    s[i].deposit(amount);
    s[i].display();
}
    cout << "this program made by 24CE030 - DHARM ." << endl;
    return 0;
}