#include <iostream>
#include <vector>

using namespace std;


void printMenu() {
    cout << "\nMenu Options:\n";
    cout << "1. Add an item to the vector\n";
    cout << "2. Print the vector\n";
    cout << "3. Double the vector\n";
    cout << "4. Find the sum of the vector\n";
    cout << "5. Print multiples of a value\n";
    cout << "6. Exit\n";
    cout << "Enter your choice: ";
}


void addItemToVector(vector<int>& vec) {
    int value;
    cout << "Enter a number to add to the vector: ";
    cin >> value;
    vec.push_back(value);
    cout << "Number added!\n";
}


void printVector(const vector<int>& vec) {
    if (vec.empty()) {
        cout << "The vector is empty.\n";
    } else {
        cout << "Vector contents: ";
        for (size_t i = 0; i < vec.size(); ++i) {
            cout << vec.at(i) << " ";
        }
        cout << endl;
    }
}


void doubleVector(vector<int>& vec) {
    for (size_t i = 0; i < vec.size(); ++i) {
        vec.at(i) *= 2;
    }
    cout << "Vector doubled!\n";
}


int calculateSum(const vector<int>& vec) {
    int sum = 0;

    for (size_t i = 0; i < vec.size(); ++i) {
        sum += vec.at(i);
    }
    return sum;
}

void printMultiplesOfValue(const vector<int>& vec) {
    int value;
    cout << "Enter a value to find multiples of: ";
    cin >> value;

    cout << "Multiples of " << value << ": ";
    bool found = false;
    for (size_t i = 0; i < vec.size(); ++i) {
        if (vec.at(i) % value == 0) {
            cout << vec.at(i) << " ";
            found = true;
        }
    }

    if (!found) {
        cout << "No multiples found.\n";
    } else {
        cout << endl;
    }
}


int main() {
    vector<int> vec;
    int choice;

    while (true) {
        printMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                addItemToVector(vec); 
                break;
            case 2:
                printVector(vec);
                break;
            case 3:
                doubleVector(vec);
                break;
            case 4:
                cout << "The sum of all numbers in the vector is: " << calculateSum(vec) << endl;
                break;
            case 5:
                printMultiplesOfValue(vec);
                break;
            case 6:
                cout << "Exiting the program.\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    }

    return 0;
}

