/*
3.4 Generic Collection Manager Using Templates
Manages arrays of various data types to perform operations like max value, reverse, and display.
Utilizes function templates to maintain reusability and flexibility for different data types.
Main Concept: Function templates, generic programming, and dynamic arrays.
*/
#include <iostream>
using namespace std;

template <typename T>
void display(T* arr, int size) {
    for (int i = 0; i < size; i++) 
    cout << arr[i] << " ";
    cout << endl;
}

template <typename T>
T findMax(T* arr, int size) {
    T maxVal = arr[0];
    for (int i = 1; i < size; i++){ 
    if (arr[i] > maxVal)
     maxVal = arr[i];
    }
    return maxVal;
}

template <typename T>
void reverseArray(T* arr, int size) {
    for (int i = 0; i < size / 2; i++)
     swap(arr[i], arr[size - i - 1]);
}

template <typename T>
void processCollection(int size) {
    T* arr = new T[size];
    for (int i = 0; i < size; i++) 
    {
        cout <<"enter elements :";
        cin >> arr[i];
    }
    display(arr, size);
    cout << "Max: " << findMax(arr, size) << endl;
    reverseArray(arr, size);
    display(arr, size);
}

int main() {
    int size, choice;
    cout<<"enter size of array:";
    cin >> size ;

    cout << "press 1.int 2.float 3.charecter" << endl;
    cin >> choice;
    if (choice == 1)
     processCollection<int>(size);
    else if (choice == 2)
     processCollection<float>(size);
    else if (choice == 3) 
    processCollection<char>(size);
    else 
    cout << "Invalid choice!";
    cout << "This program is made by 24CE030 - DHARM." << endl;
    return 0;
}
