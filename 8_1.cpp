#include <iostream>
#include <vector>
#include <algorithm>//reverse

using namespace std;

// Reverse the sequence using reverse
void reverse_with_std(vector<int>& sequence) {
    reverse(sequence.begin(), sequence.end());
}

// Reverse the sequence manually using iterators
void reverse_with_iterators(vector<int>& sequence) {
    auto left = sequence.begin();
    auto right = sequence.end();

    if (!sequence.empty()) {
        --right;
    }

    while (left < right) {
        int temp = *left;
        *left = *right;
        *right = temp;

        ++left;
        --right;
    }
}

// Print the sequence
void print_sequence(const vector<int>& sequence) {
    for (int num : sequence) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    vector<int> numbers;
    int input;

    cout << "Enter numbers (type a letter to finish): ";

    while (cin >> input) {
        numbers.push_back(input);
    }

    cin.clear();                // Clear error flag
    cin.ignore(10000, '\n');    // Discard remaining input

    vector<int> numbers_copy = numbers;

    cout << "\nOriginal sequence: ";
    print_sequence(numbers);

    reverse_with_std(numbers);
    cout << "Reversed using std::reverse: ";
    print_sequence(numbers);

    reverse_with_iterators(numbers_copy);
    cout << "Reversed using manual iterators: ";
    print_sequence(numbers_copy);

    cout << "This program is made by 24CE030 - DHARM." << endl;
    return 0;
}
