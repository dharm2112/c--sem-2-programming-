/*
4.1 Circle Area Calculator Using Inheritance
Implements shape and circle classes to compute and manage circle areas efficiently.
Explores both static and dynamic structures for handling multiple circle records.
Main Concept: Single inheritance, virtual functions, and geometric calculations.
*/
#include<iostream>
#include<vector>
using namespace std;
class shapes
{
    protected:
        float radius;
    public:
        void getdata()
        {
            cout << "Enter radius of circle : " ;
            cin >> radius;
        }
};
class circle : public shapes
{
    public:
        float area()
        {
            return 3.14*radius*radius;
        }
        void display() 
        {
             cout << "Circle with radius " << radius << " has area: " << area() << endl;
        }
};
void dynamicApproach()
{
    int n;
    cout << "\nEnter the number of circles : ";
    cin >> n;

    vector<circle> circles;
    for (int i = 0; i < n; i++)
    {
        circle temp;
        cout << "Circle " << i + 1 << ":" << endl;
        temp.getdata();
        circles.push_back(temp);
    }

    cout << "\nDisplaying Areas :\n";
    for (auto &c : circles)
    {
        c.display();
    }
}

void staticApproach()
{
    int SIZE ; 
    cout<< "enter number of circles : " ;
    cin >> SIZE;
    circle circles[SIZE];

    cout << "\nEnter data for " << SIZE << " circles:\n";
    for (int i = 0; i < SIZE; i++)
    {
        cout << "Circle " << i + 1 << ":" << endl;
        circles[i].getdata();
    }
    cout << "\nDisplaying Areas :\n";
    for (int i = 0; i < SIZE; i++)
    {
        circles[i].display();
    }
}
int main()
{
    int n;
    cout << "Press\n 1.dynamicApproach\n 2.staticApproch  " << endl;
    cout << "enter number : ";
    cin >> n;
    if(n==1)
        dynamicApproach();
    else
        staticApproach();
        cout << "This program is made by 24CE030 - DHARM." << endl;
        return 0;
}