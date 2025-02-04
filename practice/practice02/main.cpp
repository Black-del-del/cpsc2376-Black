#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <iomanip>

using namespace std;

const string filename = "account_balance.txt";

double readBalanceFromFile() {
    ifstream inFile(filename);
    double balance = 100.0; 
    if (inFile) {
        inFile >> balance;
    }
    return balance;
}

void writeBalanceToFile(double balance) {
    ofstream outFile(filename);
    if (outFile) {
        outFile << fixed << setprecision(2) << balance;
    } else {
        cerr << "Error: Unable to open file for writing." << endl;
        exit(1);
    }
}

void checkBalance(double balance) {
    cout << "Your current balance is: $" << fixed << setprecision(2) << balance << endl;
}

void deposit(double& balance) {
    double depositAmount;
    cout << "Enter deposit amount: ";
    while (true) {
        cin >> depositAmount;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Error: Please enter a valid number.\n";
        } else if (depositAmount <= 0) {
            cout << "Error: Deposit amount must be positive.\n";
        } else {
            balance += depositAmount;
            cout << "Deposit successful. Your new balance is: $" << fixed << setprecision(2) << balance << endl;
            writeBalanceToFile(balance);
            break;
        }
    }
}

void withdraw(double& balance) {
    double withdrawAmount;
    cout << "Enter withdrawal amount: ";
    while (true) {
        cin >> withdrawAmount;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Error: Please enter a valid number.\n";
        } else if (withdrawAmount <= 0) {
            cout << "Error: Withdrawal amount must be positive.\n";
        } else if (withdrawAmount > balance) {
            cout << "Error: Insufficient funds. Your balance is $" << fixed << setprecision(2) << balance << ".\n";
        } else {
            balance -= withdrawAmount;
            cout << "Withdrawal successful. Your new balance is: $" << fixed << setprecision(2) << balance << endl;
            writeBalanceToFile(balance);
            break;
        }
    }
}

void showMenu() {
    cout << "\nMenu:\n";
    cout << "1. Check Balance\n";
    cout << "2. Deposit Money\n";
    cout << "3. Withdraw Money\n";
    cout << "4. Exit\n";
}

int main() {
    double balance = readBalanceFromFile();

    cout << "Welcome to Your Bank Account!" << endl;
    checkBalance(balance);

    while (true) {
        showMenu();
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                
                checkBalance(balance);
                break;
            case 2:
                
                deposit(balance);
                break;
            case 3:
                
                withdraw(balance);
                break;
            case 4:
                
                cout << "Thank you for using our bank! Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    }

    return 0;
}
