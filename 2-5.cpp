/*
2.5 Loan Management and EMI Calculator
Stores loan ID, applicant name, amount, interest rate, and tenure.
Calculates EMI using a standard formula and shows loan summary.
Uses parameterized constructors and math operations in OOP.
*/
#include<iostream>
#include<string>
#include<cmath>
using namespace std;
class EMI
{
    double accountnumber;
    string name;
    double amount;
    float rate;
    int tenure;
    string query;

    public :
        EMI()
        {
            amount =0.0;
            rate = 0.0;
            tenure = 0;
            name ="defult name";
            accountnumber = 0.0;
        }
        EMI(double p,float r,int t,string holder,double account)
        {
            amount=p;
            rate=r;
            tenure=t;
            name=holder;
            accountnumber=account;
        }
        float calculatingEMI(double p,float r,int t)
        {
            float emi;
            emi = p*r*pow(1+r,t)/(pow(1+r,t)-1) ;
            return emi;
        }
        void queries()
        {
            cin.ignore(); // clear input buffer
            cout << "enter your loan-related queries : ";
            getline(cin , query);
            
            cout << "Thanks for give support."<< endl;
        }

        void display()
        {
            cout <<"\n\n---------------------------------------------------------" << endl;
            cout << "Member name : " << name << endl; 
            cout << "Member account number : " << accountnumber<< endl ;
            cout << "Member total loan amount : " << amount << endl;
            cout << "Member annual interest rate : " << rate << endl;
            cout << "Member total emi is :" << calculatingEMI(amount,(rate/100)/12,tenure)<< endl;
        }
};
int main()
{
    int x;
    cout << "\nEnter number of account holder : ";
    cin >> x;
    EMI accountholder[x];
    EMI a1;
    double accountnumber;
    string name;
    double amount;
    float rate;
    int tenure,n,i;

  for(i=0;i<x;i++)
  {
    cout << "\nEnter details for member " << i + 1 << endl;
    cout << "Enter member name :";
    cin >> name ;
    cout << "Enter accountnumber :";
    cin >> accountnumber;
    cout << "Enter total amount of loan :";
    cin >> amount ;
    cout << "Enter annual time (in month) :";
    cin >> tenure;
    cout << "Enter interest rate (in pr):";
    cin >> rate ;
    accountholder[i]=EMI( amount,rate,tenure,name,accountnumber);
  }

  for(i=0;i<x;i++)
  {
  accountholder[i].display();
  }

    cout << "\n\n";
    cout << "Press 1 for register your queries :";
    cin >> n ;
    if (n == 1)
    {
        for(i=0;i<x;i++)
        {
            cout << "\nEnter queries for member " << i + 1 << endl;
        accountholder[i].queries();
        }
    }
    else 
    {
        cout << "Thanks for visit ."<< endl;
    }
    cout << "this program made by 24CE030 - DHARM ." << endl;
    return 0;
}