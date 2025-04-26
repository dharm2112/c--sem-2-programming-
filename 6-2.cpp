/*
6.2 Chainable 2D Point Transformation Using this Pointer
Builds a point system where coordinates can be updated with method chaining by returning *this.
Optimizes memory usage with pass-by-reference and supports dynamic repositioning on a coordinate plane.
Main Concept: Method chaining using this pointer, pointers and references for dynamic updates.
*/
#include<iostream>
using namespace std;

class Point
{
    float x,y;

    public:
        Point(float x ,float y)
        {
            this->x =x;
            this->y =y;
        }
        Point* shift(float dx, float dy) 
        {
            x += dx;
            y += dy;
            return this;
        }
        void display() 
        {
            cout << "Final Point(" << x << ", " << y << ")\n";
        }
};
int main()
{
    float x, y;
    int n;

    cout << "Enter initial x and y: ";
    cin >> x >> y;

    Point p(x, y);
    cout << "Enter number of shifts: ";
    cin >> n;

    float shifts[n][2];

    for (int i = 0; i < n; i++) 
    {
        cout << "Enter shift " << i + 1 << " (dx dy): ";
        cin >> shifts[i][0] >> shifts[i][1];
    }
    for (int i = 0; i < n; i++) {
        p.shift(shifts[i][0], shifts[i][1]);
    }

    p.display();

    cout << "This program is made by 24CE030 - DHARM." << endl;
    return 0;
}
