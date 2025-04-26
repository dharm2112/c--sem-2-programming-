/*
5.3 2D Point Operations with Operator Overloading
Manages 2D points using a Point class with overloaded operators for negation, addition, and equality checks.
Supports dynamic undo operations through stack-based management of actions.
Main Concept: Operator overloading, custom stack or dynamic stack usage.
*/
#include<iostream>
#include<stack>
using namespace std;

class Point {
    double x;
    double y;

public:
    Point(int x = 0, int y = 0) : x(x), y(y) {}

    
    // Input method
    void input() {
        cout << "Enter x and y coordinates: ";
        cin >> x >> y;
    }

    // Unary minus operator
    Point operator -() {
        return Point(-x, -y);
    }

    // Binary addition operator
    Point operator + (Point &z) {
        return Point(x + z.x , y + z.y);
    }

    // Equality operator
    bool operator ==(Point& z) {
        return x == z.x && y == z.y;
    }

    // Display method
    void disaplay() {
        cout << "x = " << x << " & y = " << y << endl;
    }
};

int main() {
    stack<Point> history;

    Point p1,p2,p3,p4,p5;
    cout << "Enter point (p1): ";
    p1.input();

    cout << "Enter point (p2): ";
    p2.input();

    cout << "Enter point (p5): ";
    p5.input();

    // Check addition
    p3 = p1 + p2;
    cout << "Addition (p1 + p2): ";
    p3.disaplay();
    history.push(p3);  // Save to history

    // Check unary minus
    p4 = -p1;
    cout << "Negation (-p): ";
    p4.disaplay();
    history.push(p4);

    // Check equality
    if (p1 == p5) {
        cout << "p1 is equal to p5" << endl;
    } else {
        cout << "p1 is NOT equal to p5" << endl;
    }

    
    // Undo operations from history
    while (!history.empty()) {

        Point last = history.top();
        history.pop();
        cout << "Undo ---> ";
        last.disaplay();
    }

    cout << "This program is made by 24CE030 - DHARM." << endl;
    return 0;
}
