/*
5.5 Polymorphic Shape Area Calculator
Creates a base Shape class with a virtual Area() function, implemented by Rectangle and Circle derived classes.
Manages shapes dynamically using a collection for easy extensibility and area computation through base class pointers.
Main Concept: Inheritance, polymorphism, dynamic memory management.
*/
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

class shape
{
    public:
        virtual double Area()=0;
        virtual ~shape() {}
};

class rectangle : public shape 
{
    double length, width;
    public:
         rectangle(double l, double w) : length(l), width(w) {}
    
        double Area() override
        {
             return length * width;
        }
};

class circle : public shape
{
    double radius;
    public:
        circle (double r): radius(r) {}

        double Area() override
        {
            return 3.14 * radius *radius ;
        }
};

int main()
{
    vector <shape*> shapes ;

    int choice ;
    do {
        cout << "1. Add Rectangle\n";
        cout << "2. Add Circle\n";
        cout << "3. Display Areas\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            double l, w;
            cout << "Enter length and width of rectangle: ";
            cin >> l >> w;
            shapes.push_back(new rectangle(l, w));
        }
        else if (choice == 2) {
            double r;
            cout << "Enter radius of circle: ";
            cin >> r;
            shapes.push_back(new circle(r));
        }
        else if (choice == 3) {
            cout << "\nAreas of all shapes:\n";
            for (auto s : shapes) {
                cout << s->Area() << endl;
            }
        }
    } while (choice != 4);

    for (auto s : shapes) {
        delete s;
    }
    cout << "This program is made by 24CE030 - DHARM." << endl;
    return 0;

}