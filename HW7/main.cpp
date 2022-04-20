/*
Author: Asher Bolleddu
Compiler: GNU GCC
Date: 04/07/2022

Purpose of program: The program manages bank accounts.
First the user will tell the maximum number of accounts available.

Afterwards, it will display a menu with 8 options.
Option 1 will create an account, option 2 will deposit money into account, option 3 withdraws money from the account, option 4 will display all the accounts.
Option 5 deletes an owner, option 6 adds an owner, option 7 deletes an account, and option 8 exits the program.
*/

#include <iostream>
#include <string>
#include <iomanip>
#include "Account.h"

using namespace std;

// & object to memory address
// * memory address to object
const int MAX_NUM_ACCOUNTS = 4;
Account * accountArray[MAX_NUM_ACCOUNTS];

int main() {
    for (auto &i: accountArray) {
        i = nullptr;
    }

    int counter = 0;
    bool run = true;
    while (run) { // Menu
        int menuChoice = 0;
        int numOfOwners = 0;
        int accountNumber = 0;
        double amount = 0;
        cout << "Menu" << endl;
        cout << "----" << endl;
        cout << "1->Create account 2->Deposit   3->Withdraw     4->Display " << endl;
        cout << "5->Delete owner   6->Add owner 7->Delete accnt 8->Quit    " << endl;
        cin >> menuChoice;

        if (menuChoice == 8) { // Exits
            run = false;
            // release the dynamically allocated Account objects and terminate.
            for (int k = 0; k < counter;k++){
                delete accountArray[k];
            }
        }

        if (menuChoice == 1) { // Create account
            /* If accountArray length <= account index, then don't dynamically allocate an Account object
 * and display an error message */
            if (counter >= MAX_NUM_ACCOUNTS) {
                cout << "Max number of accounts reached, cannot add a new account" << endl;
            } else {
                // Prompt the user to enter the number of owners and the amount
                cout << "Enter number of owners: ";
                cin >> numOfOwners;
                cout << "Enter amount: ";
                cin >> amount;
                // Dynamically allocate an Account object
                auto *account = new Account(numOfOwners, amount);
                // Store the address of the created object into the first available element of the array of pointers
                accountArray[counter] = account;
                for (int i = 0; i < numOfOwners; i++) { // Get owner information
                    Person * person;
                    person = new Person;
                    cout << "Enter owner's name: ";
                    getline(cin >> ws,person->name);
                    cout << "Enter owner's DOB, month, day then year: ";
                    cin >> person->DOB.month ;
                    cin >> person->DOB.day;
                    cin >> person->DOB.year;
                    cout << "Enter owner's address: ";
                    getline(cin >> ws, person->address);
                    account->setOwner(i, *person);
                }
                counter++;
                cout << "Account #" << account->getAccountNumber() <<" created" << endl;
            }

        }

        if (menuChoice == 2) { // Deposit to account
            int found = -1;
            // Prompt the user to enter the account number and amount
            cout << "Enter account number: ";
            cin >> accountNumber;
            // Search if the account exists
            for (int i = 0; i < counter; i++) { // Linear search for account number
                Account * searchAccount = &(*accountArray[i]);
                if (searchAccount->getAccountNumber() == accountNumber) {
                    found = i;
                }
            }
            // If the account exists, ask for the amount to be deposited
            if (found > -1) {
                cout << "Enter amount: ";
                cin >> amount;
                // If the amount is negative, display "Amount cannot be negative, deposit not executed"
                if (amount < 0) {
                    cout << "Amount cannot be negative, deposit not executed" << endl;
                } else {
                    // Do the deposit
                    (*accountArray[found]).deposit(amount);
                    // Display the new balance
                    cout <<  "New balance is $" << fixed << setprecision(2) <<(*accountArray[found]).getBalance() << endl;
                }
            }
            // Input Validation
            if (found == -1) {
                cout << "No such account" << endl;
            }
        }

        if (menuChoice == 3) { // Withdraw from account
            int found = -1;
            // Prompt the user to enter the account number and amount
            cout << "Enter account number: ";
            cin >> accountNumber;
            // Search if the account exists
            for (int i = 0; i < counter; i++) { // Linear Search for account number
                Account * searchAccount = &(*accountArray[i]);
                if (searchAccount->getAccountNumber() == accountNumber) {
                    found = i;
                }
            }
            // If the account exists, ask for the amount to be withdrawn
            if (found > -1) {
                cout << "Enter amount: ";
                cin >> amount;
                // If the amount is negative, display "Amount cannot be negative, deposit not executed"
                if (amount < 0) {
                    cout << "Amount cannot be negative, withdrawal not executed" << endl;
                } else {
                    // Check if the balance is less that the amount withdrawn then display "Insufficient balance, withdrawal not executed"
                    if (amount > (*accountArray[found]).getBalance()) {
                        cout << "Insufficient balance, withdrawal not executed" << endl;
                    } else { // Do the withdrawal
                        (*accountArray[found]).withdraw(amount);
                        // Display the new balance
                        cout << "New balance is $" << fixed << setprecision(2) << (*accountArray[found]).getBalance()
                             << endl;
                    }

                }
            }
                // Input Validation
                if (found == -1) {
                    cout << "No such account" << endl;
                }

        }

            if (menuChoice == 4) { // Display information of all accounts
                // for each account number, display the information related to account number
                for (int i = 0; i < counter; i++) {
                    Account * acc = &(*accountArray[i]);
                    // Display the account number
                    cout << "Account Number: " << acc->getAccountNumber() << endl;
                    // Display --------------
                    cout << "--------------" << endl;
                    for (int j = 0; j < acc->getNumOwners(); j++) {
                        Person current = acc->getOwner(j);
                        // Display *Name, DOB
                        cout << "*Name: " << current.name << ", DOB: " << current.DOB.month << "/" << current.DOB.day
                             << "/" << current.DOB.year << endl;
                        // Display address
                        cout << "Address: " << current.address << endl;
                    }
                    // Display Balance
                    cout << "*Balance: $" << acc->getBalance() << " " << endl;
                }
            }

    }
    return 0;
}