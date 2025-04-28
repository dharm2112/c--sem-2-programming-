/*
First Part — Problem
Title: Memory Leak Issue in Hierarchical Object Deletion
Developers face memory leaks when deleting derived class objects through base class pointers because destructors of derived classes are not called.
Problem arises due to missing virtual destructors in the base class, causing dynamically allocated resources to remain undeleted.
Main Concept: Inheritance, destructor behavior, memory leaks due to missing virtual destructors.
*/
#include<iostream>
using namespace std;

class base
{
    public:
        base()
        {
            cout << "Base constructor called . " << endl;
        }
        ~base()
        {
            cout << "Base destructor called . " << endl;
        }
};
class derived : public base 
{
    int * data;
    public :
        derived()
        {
            data = new int[10];
            cout << "Derived constructor called . " << endl ;
        }
        ~derived()
        {
            delete[] data;
            cout << "Derived destructor called . " << endl; ;
        }
};
int main()
{
    base* ptr = new derived();
    delete ptr;

    cout << "This program is made by 24CE030 - DHARM." << endl;
    return 0;
}