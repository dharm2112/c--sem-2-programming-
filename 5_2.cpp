#include<iostream>
#include<vector>
using namespace std;

class complex
{
    double real;
    double imaginary;

    public:
        complex() : real(0), imaginary(0) {}
        complex operator +(complex &c)
        {
            complex temp;
            temp.real = real + c.real;
            temp.imaginary = imaginary + c.imaginary;
            return temp;
        }
        complex operator -(complex &c)
        {
            complex temp;
            temp.real = real - c.real;
            temp.imaginary = imaginary - c.imaginary;
            return temp;
        }
        friend istream& operator>>(istream &in, complex &c) {
            cout << "Enter real part: ";
            in >> c.real;
            cout << "Enter imaginary part: ";
            in >> c.imaginary;
            return in;
        }
        friend ostream& operator<<(ostream &out, complex &c) {
            out << c.real;
            if (c.imaginary >= 0)
                out << " + " << c.imaginary << "i";
            else
                out << " - " << -c.imaginary << "i";
            return out;
        }
};
int main()
{
    int n;
    cout << "How many complex numbers do you want to enter? ";
    cin >> n;

    vector<complex> numbers(n);

    for (int i = 0; i < n; i++) {
        cout << "\nEnter complex number " << i + 1 << ":\n";
        cin >> numbers[i];
    }

    cout << "\nEntered complex Numbers:\n";
    for (int i = 0; i < n; i++) {
        cout << "complex " << i + 1 << ": " << numbers[i] << endl;
    }

    complex sum = numbers[0];
    complex diff = numbers[0];

    for (int i = 1; i < n; i++) {
        sum = sum + numbers[i];
        diff = diff - numbers[i];
    }
    cout << "Sum: " << sum << endl;
    cout << "Difference: " << diff << endl;

    cout << "This program is made by 24CE030 - DHARM." << endl;
return 0;
}