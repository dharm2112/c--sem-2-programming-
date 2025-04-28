/*
Second Part — Solution
Title: Solving Memory Leaks with Virtual Destructors
By declaring the base class destructor as virtual, the derived class destructors are properly invoked when deleting through base class pointers.
Ensures correct deallocation of dynamically allocated memory using raw pointers and manual new/delete operations.
Main Concept: Virtual destructors, safe manual memory management, resource deallocation in inheritance.
*/
#include<iostream>
using namespace std;

class base
{
    public:
        base()
        {
            cout << "Base constructor called." << endl;
        }
        virtual ~base()
        {
            cout << "Base destructor called." << endl;
        }
};

class derived : public base 
{
    int* data;
    public:
        derived()
        {
            data = new int[10];
            cout << "Derived constructor called." << endl;
        }
        ~derived()
        {
            delete[] data;
            cout << "Derived destructor called." << endl;
        }
};

int main()
{
    base* ptr = new derived();
    delete ptr;

    cout << "This program is made by 24CE030 - DHARM." << endl;
    return 0;
}
