#include<iostream>
#include<vector>
using namespace std;

class Calculator {
public:
    int add(int a, int b) {
        cout << "Adding integers: " << a << " + " << b << " = ";
        return a + b;
    }

    double add(double a, double b) {
        cout << "Adding doubles: " << a << " + " << b << " = ";
        return a + b;
    }

    double add(int a, double b) {
        cout << "Adding int and double: " << a << " + " << b << " = ";
        return a + b;
    }

    double add(double a, int b) {
        cout << "Adding double and int: " << a << " + " << b << " = ";
        return a + b;
    }
};

int main() {
    Calculator calc;
    vector<double> stl;

    stl.push_back(calc.add(10, 230));
    cout << stl.back() << endl;
    stl.push_back(calc.add(10.23, 230));
    cout << stl.back() << endl;
    stl.push_back(calc.add(7, 20.7));
    cout << stl.back() << endl;
    stl.push_back(calc.add(1.4, 2.9));
    cout << stl.back() << endl;
    cout << "-------------------------------------------------" << endl << endl;
    double results[4];

    results[0] = calc.add(10, 230);
    cout << results[0] << endl;
    results[1] = calc.add(10.23, 230);
    cout << results[1] << endl;
    results[2] = calc.add(7, 20.7);
    cout << results[2] << endl;
    results[3] = calc.add(1.4, 2.9);
    cout << results[3] << endl;

    cout << "This program is made by 24CE030 - DHARM." << endl;
    return 0;
}
