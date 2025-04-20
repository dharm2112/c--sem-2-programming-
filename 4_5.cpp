/*
4.5 Advanced Grading System
Uses protected marks with abstraction, inheritance, and polymorphism for flexible grading.
Abstract class defines grading; derived classes compute grades for UG and PG students.
Manages student records with customized evaluation logic.
*/
#include<iostream>
#include<vector>
using namespace std;
class Student
{
    protected:
        string name;
        int marks;
    public:
    void setData(string n, int m)
    {
        name = n;
        marks = m;
    }

    virtual string computeGrade() = 0;
    string getName(){ 
        return name;
     }
    int getMarks(){ 
        return marks;
     }
    virtual string getLevel() = 0;
    virtual ~Student() {} ;
};

// Undergraduate class
class Undergraduate : public Student
 {
    public:
        string computeGrade() override {
            if (marks >= 85) return "A";
            else if (marks >= 70) return "B";
            else if (marks >= 50) return "C";
            else return "F";
        }
        string getLevel() override {
            return "Undergraduate";
        }
};
    
// Postgraduate class
class Postgraduate : public Student 
{
    public:
        string computeGrade() override {
            if (marks >= 90) return "A";
            else if (marks >= 75) return "B";
            else if (marks >= 60) return "C";
            else return "F";
        }
    
        string getLevel()  override{
            return "Postgraduate";
        }
    };
int main() 
{
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    vector<Student*> students;

    for (int i = 0; i < n; ++i) {
        string name, level;
        int marks;

        cout << "\nEnter name of student #" << i + 1 << ": ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter marks: ";
        cin >> marks;
        cout << "Enter level (Undergraduate/Postgraduate): ";
        cin >> level;

        Student* student = nullptr;

        if (level == "Undergraduate" || level == "undergraduate") {
            student = new Undergraduate();
        } else if (level == "Postgraduate" || level == "postgraduate") {
            student = new Postgraduate();
        } else {
            cout << "Invalid level. Skipping student.\n";
            continue;
        }

        student->setData(name, marks);
        students.push_back(student);
    }
    cout << "\nResults:\n";
    for (auto s : students) {
        cout << s->getName() << " is a " << s->getLevel()
             << " student. who scored " << s->getMarks()
             << " marks and received a grade of " << s->computeGrade() << ".\n";
    }
    cout << "This program is made by 24CE030 - DHARM." << endl;
return 0 ;
}
