#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <string>
#include <sstream>

using namespace std;

struct Student {
    string name;
    int marks;
    char grade;
};

vector<Student> students;

ostream& tab_align(ostream& os) {
    os << left << setw(25);  // Adjusted width to handle longer names
    return os;
}

void load_students(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Unable to open file.\n";
        exit(1);
    }

    Student s;
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        
        // Read the name with spaces
        getline(ss, s.name, ',');  // Assuming name is separated by commas
        ss >> s.marks;
        ss >> s.grade;

        students.push_back(s);
    }

    file.close();
}

void display_report() {
    cout << tab_align << "Name"
         << setw(10) << "Marks"
         << setw(10) << "Grade" << endl;
    cout << string(45, '-') << endl;

    for (const auto& s : students) {
        cout << tab_align << s.name
             << setw(10) << s.marks
             << setw(10) << s.grade << endl;
    }
}

int main() {
    load_students("students.txt");
    display_report();

    cout << "This program is made by 24CE030 - DHARM." << endl;
    return 0;
}
