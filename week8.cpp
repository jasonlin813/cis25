#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// BankAccount class definition
class BankAccount {
private:
    double balance; // To store account balance

    // Save transaction to file
    void saveTransaction(string type, double amount) {
        ofstream file("transactions.txt", ios::app);
        if (file.is_open()) {
            file << type << ": $" << amount << endl;
            file.close();
        }
    }

public:
    // Constructor to initialize balance to 0
    BankAccount() {
        balance = 0.0;
    }

    // Method to deposit money into the account
    void deposit(double amount) {
        balance += amount;
        cout << "Deposit amount: $" << amount << endl;
        saveTransaction("Deposit", amount);
    }

    // Method to make a purchase and deduct from the balance
    void makePurchase(string item, double cost) {
        if (cost > balance) {
            cout << "Insufficient balance, unable to purchase: " << item << endl;
            saveTransaction("Failed purchase - " + item, cost);
        } else {
            balance -= cost;
            cout << "Purchased: " << item << ", cost $" << cost << endl;
            saveTransaction("Purchase - " + item, cost);
        }
    }

    // Method to display the current balance
    void displayBalance() {
        cout << "Current balance: $" << balance << endl;
        saveTransaction("Final balance", balance);
    }
};

// Main function
int main() {
    // Create a BankAccount object
    BankAccount myAccount;

    // Add an initial deposit
    myAccount.deposit(200.00);

    // Make purchases
    myAccount.makePurchase("Daily necessities", 50.25);
    myAccount.makePurchase("Gas", 30.00);

    // Display the final balance
    myAccount.displayBalance();

    return 0;
}

