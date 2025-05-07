#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

struct Student {
    string name;
    double marks;
    double tuition_fee;
};

string currency(const string& symbol, double amount) {
    ostringstream out;
    out << symbol << fixed << setprecision(2) << amount;
    return out.str();
}

void display_header() {
    cout << left << setw(15) << "Name"
         << right << setw(10) << "Marks"
         << right << setw(18) << "Tuition Fee" << endl;
    cout << setfill('-') << setw(45) << "-" << setfill(' ') << endl;
}

void display_students(const vector<Student>& students, const string& symbol) {
    for (const auto& s : students) {
        cout << left << setw(15) << s.name
             << right << setw(10) << fixed << setprecision(2) << s.marks
             << right << setw(18) << currency(symbol, s.tuition_fee) << endl;
    }
}

int main() {
    vector<Student> students = {
        {"Dharm", 89.5, 12000.75},
        {"Dev", 76.0, 9500.5},
        {"Chakalo", 91.25, 13400.0}
    };

    string currency_symbol = "Rs.";
    display_header();
    display_students(students, currency_symbol);

    cout << "This program is made by 24CE030 - DHARM." << endl;
    return 0;
}
