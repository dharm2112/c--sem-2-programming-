/*
5.4 Temperature Conversion System Using Operator Overloading
Implements Celsius and Fahrenheit classes with type conversion and equality checking through operator overloading.
Manages multiple temperature conversions using either a dynamic queue or static array.
Main Concept: Operator overloading, dynamic queue management, type conversion.
*/
#include<iostream>
#include<queue>
using namespace std;

class fahrenheit;
class celsius
{
    double temp;
    public :
        celsius(double c=0.0) : temp(c) {}
        operator fahrenheit();

        double gettempc(){
            return temp;
        }
        bool operator==(celsius& other)
        {
            return temp== other.temp;
        }
};
class fahrenheit
{
    double temp;
    public:
        fahrenheit(double f=32) : temp(f){}
        operator celsius(){
            return celsius((temp -32)*5/9);
        }

        double gettempf(){
            return temp;
        }
        bool operator==(fahrenheit & other)
        {
            return temp == other.temp ;
        }
};
celsius::operator fahrenheit() 
{
    return fahrenheit((temp * 9 / 5) + 32);
}

int main(){
    queue<fahrenheit> tempQueue;
    int n;
    cout << "Enter number of temperatures: ";
    cin >> n;

    for (int i = 0; i < n; ++i) {
        double celsiusValue;
        cout << "Enter temperature in Celsius: ";
        cin >> celsiusValue;
        celsius c(celsiusValue);
        tempQueue.push(c);
    }

    cout << "\nTemperatures in Fahrenheit:\n";
    queue<fahrenheit> tempCopy = tempQueue;
    while (!tempCopy.empty()) {
        cout << tempCopy.front().gettempf() << " F ";
        tempCopy.pop();
    }
    cout << endl;

    cout << "\nDequeuing one element...\n";
    if (!tempQueue.empty()) {
        cout << "Dequeued: " << tempQueue.front().gettempf() << " F" << endl;
        tempQueue.pop();
    }

    cout << "\nRemaining temperatures:\n";
    tempCopy = tempQueue;
    while (!tempCopy.empty()) {
        cout << tempCopy.front().gettempf() << " F ";
        tempCopy.pop();
    }
    cout << endl;

    cout << "This program is made by 24CE030 - DHARM." << endl;
    return 0;
}