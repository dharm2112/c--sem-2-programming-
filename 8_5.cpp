#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std; 

void add_folder(map<string, vector<string>>& dir, string name) {
    dir[name];
}

void add_file(map<string, vector<string>>& dir, string folder, string file) {
    dir[folder].push_back(file);
}

void show_dir(const map<string, vector<string>>& dir) {
    cout << "\nDirectory:\n";
    for (auto it = dir.begin(); it != dir.end(); ++it) {
        cout << it->first << ":\n";
        for (auto f = it->second.begin(); f != it->second.end(); ++f) {
            cout << "  - " << *f << "\n";
        }
    }
}

int main() {
    map<string, vector<string>> dir;
    int choice;
    string folder, file;

    while (true) {
        cout << "\n1. Add Folder\n2. Add File\n3. Show Directory\n4. Exit\nChoice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Folder name: ";
            cin >> folder;
            add_folder(dir, folder);
        }
        else if (choice == 2) {
            cout << "Folder name: ";
            cin >> folder;
            cout << "File name: ";
            cin >> file;
            add_file(dir, folder, file);
        }
        else if (choice == 3) {
            show_dir(dir);
        }
        else if (choice == 4) {
            break;
        }
        else {
            cout << "Invalid choice.\n";
        }
    }

    cout << "\nThis program is made by 24CE030 - DHARM." << endl;
    return 0;
}
