/*
2.1 Rectangle Area and Perimeter Calculator
Handles rectangle dimensions and calculates area and perimeter.
Allows updating length and width for each rectangle.
Uses OOP with encapsulation and method-based calculations.
*/
#include<iostream>
using namespace std;
class Rectangle
{
    int length;
    int width;

    public :
    Rectangle(){}
    //parameterized constructor
    Rectangle(int l,int w)
    {
        length=l;
        width=w;
    }
    void updet_Dimensions (int l,int w)
    {
        if (l > 0 && w > 0) {
            length = l;
            width = w;
        } else {
            cout << "Error: Length and width must be positive values.\n";
        }
    }
    int getarea()
    {
        return length*width;
    }
    int getperimeter()
    {
        return 2*(length + width);
    }
    void display()
    {
         cout << "Rectangle ---->  Length: " << length << ", Width: " << width << "\n";
        cout << "Area: " << getarea() << "\n";
        cout << "Perimeter: " << getperimeter() << "\n";
        cout << "----------------------------\n";
    }
};
int main()
{
    Rectangle Rect[10];
    int choice,count =0;

    do
    {
        cout << "\nWelcome to Rectangle Management System\n";

        cout << "press number to select option\n";
        cout << "1. Add a Rectangle\n";
        cout << "2. Update a Rectangle\n";
        cout << "3. Display All Rectangles\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            if(count < 10)
            {
                int l,w;
                 cout << "Enter length and width: ";
                cin >> l >> w;
                Rect[count] = Rectangle(l,w);
                count++;
                cout << "Rectangle added successfully!\n";
            } else {
                cout << "Error: Maximum rectangle limit reached.\n";
            }
            break;
        
        case 2:
              int index;
            cout << "Enter rectangle index (0 - " << count  << "): ";
            cin >> index;
            if (index >= 0 && index < count) {
                double l, w;
                cout << "Enter new length and width: ";
                cin >> l >> w;
                Rect[index].updet_Dimensions(l, w);
                cout << "Rectangle updated successfully!\n";
            } else {
                cout << "Error: Invalid index.\n";
            }
            break;

        case 3:
            if (count == 0) {
                cout << "No rectangles available.\n";
            } else {
                for (int i = 0; i < count; i++) {
                    cout << "Rectangle " << i + 1 << ":\n";
                    Rect[i].display();
                }
            }
            break;

        case 4:
             cout << "Exiting program...\n";
             cout << "this program made by 24CE030 - DHARM ." << endl;
             break;

        default:
             cout << "Invalid choice! Please enter a valid option.\n";
             cout << "this program made by 24CE030 - DHARM ." << endl;
            break;
        }
    } while (choice != 4);
    return 0;
}