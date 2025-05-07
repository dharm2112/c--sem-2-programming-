#include <iostream>
#include <set>
#include <iterator>

using namespace std;

int main() {
    set<int> transaction_ids;
    int id;

    cout << "Enter transaction IDs (type a letter to stop): ";

    while (cin >> id) {
        transaction_ids.insert(id);
    }

    cin.clear();
    cin.ignore(10000, '\n');

    cout << "\nUnique Transaction IDs (sorted):\n";
    for (auto it = transaction_ids.begin(); it != transaction_ids.end(); ++it) {
        cout << *it << " ";
    }

    cout << "\n \nThis program is made by 24CE030 - DHARM." << endl;
    return 0;
}
