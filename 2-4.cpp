/*
2.4 Advanced Inventory Management System
Tracks item ID, name, price, and quantity in stock.
Handles stock updates, sales, and displays inventory details.
Implements arrays of objects and real-world simulations in OOP.
*/
#include<iostream>
using namespace std;
class inventory
{
    int ID;
    string name;
    double price;
    int quantity;

    public :
    inventory()
    {
        ID = 0;
        name ="defualt name";
        price =0.0;
        quantity =0;
    }
      //parameterized constructor
    inventory(int id ,string Name,double amount,int number)
    {
        ID = id;
        name = Name;
        price = amount;
        quantity = number;
    }
    void increasingstock(int n)
    {
        quantity += n;
        cout << "Stock of this " << name << " increas and new stock is " << quantity << endl;
    }
    void decreasingstock(int n)
    {
        if(quantity < n)
        {
            cout << "\nError : please re-check quantity";
        }
        else
        {
            quantity =quantity - n;
            cout << "stock of this " << name << " decreas and new stock is "<< quantity << endl;
        }
    }
    
    void display()
    {
        cout << "Welcome to a digital inventory management system." << endl;
        cout << "iteam name :" << name << endl;
        cout << "number :" << ID << endl;
        cout << "price :" << price << endl;
        cout << "quantity :"<< quantity << endl;
    }
    int getQuantity() const 
    {
        return quantity;
    }
};

int main()
{
    int ID;
    string name;
    double price;
    int quantity;
    int n,i,x,y,z,increasevalue,decreasevalue;
    cout << "\nEnter number of iteam : ";
    cin >> x;
    inventory item[x];

    for (i=0;i<x ;i++)
    {
        cout << "\nEnter details for item " << i + 1 << endl;
            cout << "enter iteam name :";
            cin >> name;
            cout << "enter id number :";
            cin >> ID;
            cout << "enter price :";
            cin >> price;
            cout << "enter quntity :";
            cin >> quantity;
            item[i]= inventory(ID,name ,price ,quantity);
    }
    
    cout << "\nPress number :" << endl;
    while(!0)  
{
    cout << "increase stock 1 and decrease stock 2. and exit 0:    ";
    cin >> z;
        if (z==1)
    {
        cout << "Enter id number :";
        cin >> y ;
        cout << "Enter quntity :";
        cin >> increasevalue;
    
        item[y-1].increasingstock(increasevalue);
    }
    else if (z==2)
    {
        cout << "Enter id number :";
        cin >> y ;
        cout << "Enter quntity :";
        cin >> decreasevalue;
    
        item[y-1].decreasingstock(decreasevalue);
    }
    else
        break;
}
    for (i=0;i<x;i++)
    {
        item[i].display();
    }
    cout << "this program made by 24CE030 - DHARM ." << endl;
    return 0;
}