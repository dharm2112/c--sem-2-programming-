/*
2.2 Student Record Management System
Stores roll number, name, and marks for three subjects.
Calculates and displays average marks per student.
Uses constructors, encapsulation, and multiple object management.
*/
#include<iostream>
using namespace std;
class student 
{
    int rollnumber;
    string name;
    float M1,M2,M3;

    public :
        student (){}
         //parameterized constructor
        student(int rn ,string sname,float m1 ,float m2, float m3)
        {
            rollnumber=rn;
            name=sname;
            M1 = m1;
            M2 = m2;
            M3 = m3;
        }
        float Average()
        {
            return (M1 +M2 +M3) / 3 ;
        }
        void display()
        {
            cout << "\n\nWelcome to collage page .\n";
            cout << "Name : " << name;
            cout << "\nID nomber : " << rollnumber;
            cout << "\nMarks : " << M1 <<", " << M2 << ", " <<M3 ;
            cout << "\nAverage marks : " << Average() << endl ;
        }
};
int main ()
{
    int n,i;
    int rollnumber;
    string name;
    float M1,M2,M3;

    cout << "\nEnter student number :";
    cin >> n;

    student s[n];

    for(i=0 ;i<n ;i++)
    {
            cout << i+1 << ". student";       
            cout << "\nEnter student name :";
            cin >> name;
            cout << "enter id :";
            cin >> rollnumber;
            cout << "enter your marks :";
            cin >> M1 ;
            cout << "enter your marks :";
            cin >> M2 ;
            cout << "enter your marks :";
            cin >>  M3;
            s[i]= student(rollnumber ,name,M1 ,M2 ,M3);
    }
   
    cout << "Student Records:";
    cout << "------------------------------------------" ;
    for (i=0 ; i<n ;i++)
    {
        s[i].display();
    }
    cout << "this program made by 24CE030 - DHARM ." << endl;
    return 0;
}