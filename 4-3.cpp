/*
4.3 Vehicle Information System
Manages car details by integrating fuel type and brand using hierarchical class structure.
Uses constructors for initialization and organizes cars for operations like servicing.
Main Concept: Multiple inheritance, constructor overloading, and class composition.
*/
#include<iostream>
#include<queue>
using namespace std;

class Fuel
{
    protected:
        string fueltype;
    public:
        Fuel(string type) 
         {
            fueltype = type ;
         }
        void displayFuelType()
        {
            cout << "Fuel Type: " << fueltype << endl;
        }
};
class Brand
{
    protected:
        string brandname;
    public:
        Brand(string name )
        {
            brandname = name;
        }
        void displayBrandName() 
        {
            cout << "Brand: " << brandname << endl;
        }
};
class Car : public Fuel, public Brand
{
    public:
        Car(string fuel,  string brand): Fuel(fuel), Brand(brand) { }

        void displayCarInfo() 
        {
            cout << "Car Information:" << endl;
            displayBrandName();
            displayFuelType();
            cout << "------------------------" << endl;
        }
};
int main()
{
    queue<Car> serviceQueue;
    int numberOfCars;

    cout << "Enter number of cars to input: ";
    cin >> numberOfCars;
    cin.ignore();
    
    for (int i = 0; i < numberOfCars; ++i) {
        string brand, fuel;
 
        cout << "Enter brand for car " << (i + 1) << ": ";
        getline(cin, brand);

        cout << "Enter fuel type for car " << (i + 1) << ": ";
        getline(cin, fuel);
        Car newCar(fuel, brand);
        serviceQueue.push(newCar);
        cout << "Car added to service queue.\n\n";
    }

    cout << "\n--- Displaying All Car Information ---\n";
    while (!serviceQueue.empty()) {
        Car currentCar = serviceQueue.front();
        currentCar.displayCarInfo();
        serviceQueue.pop();
    }
    cout << "This program is made by 24CE030 - DHARM." << endl;
    return 0;
}