/*
6.1 Custom Dynamic Array Management without STL
Designs a custom memory management system for dynamic arrays, enabling efficient insertion and deletion by using raw pointers.
Focuses on avoiding memory leaks and improving flexibility in resource-constrained environments.
Main Concept: Pointers, manual dynamic memory allocation, efficient array management.
*/
#include <iostream>
using namespace std;

class DynamicArray {
private:
    int* data;
    int size;
    int capacity;

    void resize() {
        int newCapacity = capacity * 2;
        int* newData = new int[newCapacity];
        for (int i = 0; i < size; ++i)
            newData[i] = data[i];
        delete[] data;
        data = newData;
        capacity = newCapacity;
    }

public:
    DynamicArray(int initialCapacity = 4) {
        data = new int[initialCapacity];
        size = 0;
        capacity = initialCapacity;
    }

    ~DynamicArray() {
        delete[] data;
    }

    void insert(int value) {
        if (size == capacity)
            resize();
        data[size++] = value;
    }

    void remove(int index) {
        if (index < 0 || index >= size) {
            cout << "Invalid index: " << index << "\n";
            return;
        }
        for (int i = index; i < size - 1; ++i)
            data[i] = data[i + 1];
        --size;
    }

    void display() {
        cout << "Array: ";
        for (int i = 0; i < size; ++i)
            cout << data[i] << " ";
        cout << "\n";
    }
};

int main() {
    DynamicArray arr;
    int n, val;

    cout << "How many elements do you want to insert? ";
    cin >> n;
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; ++i) {
        cin >> val;
        arr.insert(val);
    }

    cout << "After insertion:\n";
    arr.display();

    int m, index;
    cout << "How many elements do you want to remove? ";
    cin >> m;

    cout << "Enter " << m << " indices to remove:\n";
    for (int i = 0; i < m; ++i) {
        cin >> index;
        arr.remove(index);
    }

    cout << "After deletion:\n";
    arr.display();

    cout << "This program is made by 24CE030 - DHARM." << endl;
    return 0;
}
