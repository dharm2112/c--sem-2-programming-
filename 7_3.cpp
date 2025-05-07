
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

struct Product {
    string name;
    int quantity;
    double price;
};

const string inventory_file = "inventory.txt";
vector<Product> inventory;

void load_inventory() {
    inventory.clear();
    ifstream file(inventory_file);
    string line;

    while (getline(file, line)) {
        stringstream ss(line);
        Product product;
        getline(ss, product.name, ',');
        ss >> product.quantity;
        ss.ignore();
        ss >> product.price;
        inventory.push_back(product);
    }
    file.close();
}

void add_product() {
    Product product;
    cout << "Enter product name: ";
    cin.ignore();
    getline(cin, product.name);
    cout << "Enter quantity: ";
    cin >> product.quantity;
    cout << "Enter price: ";
    cin >> product.price;

    ofstream file(inventory_file, ios::app);
    file << product.name << "," << product.quantity << "," << product.price << endl;
    file.close();

    inventory.push_back(product);

    cout << "Product added successfully.\n";
}

void view_inventory() {
    cout << left << setw(20) << "Name" << setw(10) << "Quantity" << setw(10) << "Price" << endl;
    cout << "--------------------------------------------\n";
    for (const auto& product : inventory) {
        cout << left << setw(20) << product.name
             << setw(10) << product.quantity
             << fixed << setprecision(2) << product.price << endl;
    }
}

void search_product() {
    cin.ignore();
    string search_name;
    cout << "Enter product name to search: ";
    getline(cin, search_name);

    bool found = false;
    for (const auto& product : inventory) {
        if (product.name == search_name) {
            cout << "Product found:\n";
            cout << "Name: " << product.name
                 << "\nQuantity: " << product.quantity
                 << "\nPrice: $" << fixed << setprecision(2) << product.price << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Product not found.\n";
    }
}

int main() {
    load_inventory();

    int choice;
    do {
        cout << "\nInventory Management System\n";
        cout << "1. Add Product\n2. View Inventory\n3. Search Product\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: add_product(); break;
            case 2: view_inventory(); break;
            case 3: search_product(); break;
            case 4: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 4);

    cout << "This program is made by 24CE030 - DHARM." << endl;
    return 0;
}
