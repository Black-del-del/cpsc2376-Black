#include <iostream>
#include <fstream>
#include <iomanip>
#include <limits>

using namespace std;

double readBalanceFromFile();
void writeBalanceToFile(double balance);
void checkBalance(double balance);
bool deposit(double &balance, double amount);
bool withdraw(double &balance, double amount);
void displayMenu();

int main() {
    double balance = readBalanceFromFile();

    cout << "Welcome to Your Bank Account!" << endl;
    cout << "Your current balance is: $" << fixed << setprecision(2) << balance << endl;

    int choice;
    double amount;

    while (true) {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        if (cin.fail() || choice < 1 || choice > 4) {
            cout << "Invalid choice. Please try again." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (choice) {
            case 1:
                checkBalance(balance);
                break;
            case 2:
                cout << "Enter deposit amount: $";
                cin >> amount;

                if (cin.fail() || amount <= 0) {
                    cout << "Error: Deposit amount must be positive." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    break;
                }

                if (deposit(balance, amount)) {
                    cout << "Deposit successful. Your new balance is: $" << fixed << setprecision(2) << balance << endl;
                    writeBalanceToFile(balance);
                }
                break;
            case 3:
                cout << "Enter withdrawal amount: $";
                cin >> amount;

                if (cin.fail() || amount <= 0) {
                    cout << "Error: Withdrawal amount must be positive." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    break;
                }

                if (withdraw(balance, amount)) {
                    cout << "Withdrawal successful. Your new balance is: $" << fixed << setprecision(2) << balance << endl;
                    writeBalanceToFile(balance);
                } else {
                    cout << "Error: Insufficient funds. Your balance is $" << fixed << setprecision(2) << balance << endl;
                }
                break;
            case 4:
                cout << "Exiting the program. Goodbye!" << endl;
                return 0;
        }
    }
}

double readBalanceFromFile() {
    ifstream inFile("account_balance.txt");
    double balance;

    if (!inFile) {
        cout << "Initializing account with $100.00..." << endl;
        balance = 100.00;
        writeBalanceToFile(balance);
    } else {
        inFile >> balance;
    }

    inFile.close();
    return balance;
}

void writeBalanceToFile(double balance) {
    ofstream outFile("account_balance.txt");

    if (!outFile) {
        cout << "Error: Could not open the file to write." << endl;
        exit(1);
    }

    outFile << fixed << setprecision(2) << balance;
    outFile.close();
}

void checkBalance(double balance) {
    cout << "Your current balance is: $" << fixed << setprecision(2) << balance << endl;
}

bool deposit(double &balance, double amount) {
    balance += amount;
    return true;
}

bool withdraw(double &balance, double amount) {
    if (amount > balance) {
        return false;
    }
    balance -= amount;
    return true;
}

void displayMenu() {
    cout << "\nMenu:" << endl;
    cout << "1. Check Balance" << endl;
    cout << "2. Deposit Money" << endl;
    cout << "3. Withdraw Money" << endl;
    cout << "4. Exit" << endl;
}
