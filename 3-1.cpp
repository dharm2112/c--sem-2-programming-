/*
3.1 Payroll Management System
Manages employee salary by storing name, basic salary, and a customizable bonus.
Calculates total salary using an inline function and stores data dynamically for scalability.
Main Concept: Inline functions, constructors, and dynamic memory allocation.
*/
#include<iostream>
#include<vector>
using namespace std;
class company
{
    string name;
    double salary;
    double bonus;

    public :
     company(string empname, double s, double empbonus = 500.0) {
        name = empname;
        salary = s;
        bonus = empbonus;
    }

        inline double calculate_salary()
        {
            cout<<salary<<" + "<<bonus << "= ";
            return salary + bonus;
        }

        void display() 
        {
            cout << "Employee Name: " << name << endl;
            cout << "Basic Salary: $" << salary << endl;
            cout << "Bonus: $" << bonus << endl;
            cout << "Total Salary: $" << calculate_salary() << endl;
            cout << "---------------------------" << endl;
        }
};
int main() 
{
    vector <company> employee;
    int numEmployees;
    cout << "Enter the number of employees: ";
    cin >> numEmployees;

    for (int i=0;i<numEmployees;i++)
    {
        string name;
        double salary1;
        double bonus;
        cout << "Enter name for employee : ";
        cin >> name;
        cout << "Enter basic salary: ";
        cin >> salary1;
        cout << "Enter bonus: ";
        cin >> bonus;
        employee.emplace_back(name ,salary1 ,bonus);
    }

    cout << "\nEmployee Payroll Details:\n";
    for ( auto& emp : employee)
    {
        emp.display();
    }
    cout << "this program made by 24CE030 - DHARM ." << endl;
return 0 ;
}