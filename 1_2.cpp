/*1.2 Inventory Management System
Manages product details including ID, name, price, and quantity.
Allows adding/updating stock and calculating total inventory value.
Compares procedural vs object-oriented programming approaches.*/
#include<iostream>
using namespace std;
class management_system
{
    int ID;
    char name[15];
    int quantity;
    float price;

    public :
    void getdata()
    {
       cout << "\nEnter the id of product :";
       cin >> ID;
       cout << "Enter the iteam name :";
       cin >> name;
       cout << "Enter quantity of iteam :";
       cin >> quantity;
       cout << "Enter price of iteam :";
       cin >> price;
    }
    float calculate_amount()
    {
        return quantity * price ;
    }
};
int main()
{
    int n,i,j;
    float total_price=0,total_sell=0,left;
    cout << "\nenter number of iteam to add in list :";
    cin >> n;
    management_system iteam[n],solditeam[n];

    for(i=0;i<n;i++)
    {
        cout << i+1 << " Product Details :" ;
        iteam[i].getdata();
        cout << endl;
    }
     
    cout << "\nPress one for sold iteam .";
       
        cin >> j;
     if(j==1)
    {    
     cout << "\nIf any iteam sold , give iteam data :";
    for(i=0;i<n;i++)
    {
        cout<< i+1 << " Product sell Details :";
        solditeam[i].getdata();
        cout << endl;
    }
    for(i=0;i<n;i++)
    {
        total_sell += solditeam[i].calculate_amount();
    }
    }
    
   for(i=0;i<n;i++)
    {
        total_price += iteam[i].calculate_amount();
    }

    left = total_price - total_sell;
    if(left < 0)
        cout << "\nyour amount is " << left << "left";
    else if (left > 0)
        cout << "\nyou have " << left << " amount iteam is left.";
    else    
    cout << "\nyou have sucucessfully all iteam sell.";
    cout << "this program made by 24CE030 - DHARM ." << endl;
    return 0;
}