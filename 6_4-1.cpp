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