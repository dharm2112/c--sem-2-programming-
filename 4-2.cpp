/*
4.2 Organizational Hierarchy System
Models a person-to-manager hierarchy using multilevel inheritance with constructors at each level.
Displays individual and organizational details with methods to manage multiple records.
Main Concept: Multilevel inheritance, constructor chaining, and class hierarchy.
*/
#include<iostream>
#include<map>
using namespace std;

class person
{
    protected:
        string name;
        int age;
    public:
        person (string n , int a)
        {
            name = n;
            age = a;
        }
        void display()
        {
            cout << "Name : " << name << endl;
            cout << "Age : " << age << endl;
        }
};
class employee : public person
{
    protected:
        int ID;
    public:
        employee(string n,int a,int id) : person(n,a)
        {
            ID = id;
        }
        void displayemployee(){
            display();
            cout << "employee id is  " << ID << endl;
        }

};
class manager : public employee
{
    protected:
        string type;
    public:
        manager() : employee("", 0, 0), type("") {}

        manager(string n,int a,int id,string dept) : employee(n,a,id){
            type = dept;
        }
        void displaymanager()
        {
            displayemployee();
            cout << "manager department is " << type << endl;
        }
    };

int main()
{
    int numManagers;

    cout << "Enter number of managers: ";
    cin >> numManagers;

    manager managerArray[numManagers]; 
    map<int, manager> managers;
    for (int i = 0; i < numManagers; ++i) {
        string name, dept;
        int age, id;

        cout << "\nEnter details for manager " << i + 1 << ":" << endl;
        cout << "Name: ";
        cin >> ws;
        getline(cin, name);
        cout << "Age: ";
        cin >> age;
        cout << "Employee ID: ";
        cin >> id;
        cout << "Department: ";
        cin >> ws;
        getline(cin, dept);

        managerArray[i] = manager(name, age, id, dept);
        managers[id] = managerArray[i];
    }
        cout << "--- Manager Details ---" << endl;

        for (auto it = managers.begin(); it != managers.end(); ++it) 
        {
            cout << "\nManager with ID: " << it->first << endl;
            it->second.displaymanager();
        }  
        cout << "This program is made by 24CE030 - DHARM." << endl;
        return 0;
}