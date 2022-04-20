/*
Author: Asher Bolleddu
Compiler: GNU GCC
Date: 03/23/2022

Purpose of program: The program manages bank accounts.
First the user will tell the maximum number of accounts available.

Afterwards, it will display a menu with 4 options.
Option 1 will prompt the user for account data to save, option 2 will search for a specific account number and display the data,
Option 3 will display all the data of all bank accounts, and option 4 exits.
*/

#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>


using namespace std;

struct Person
{
    string name;
    string address;
};

struct Account
{
    int accountNumber;
    Person ownerInfo;
    double balance;
};


int isNumber(string w){ // Checks if the string is an integer
    bool whitespaceEnds = false;
    for (char i : w) {
        if (i != ' '){
            whitespaceEnds = true;
        }
        if (i == ' ' && !whitespaceEnds){
            whitespaceEnds = true;
            continue;
        }
        if (!isdigit(i)){
            return false;
        }
    }
    return true;
}

int isDecimalNumber(string w){ // Checks if the string is a decimal number
    bool whitespaceEnds = false;
    for (char i : w) {
        if (i != ' '){
            whitespaceEnds = true;
        }
        if (i == ' ' && !whitespaceEnds){
            whitespaceEnds = true;
            continue;
        }
        if (!isdigit(i) && i != '.'){
            return false;
        }
    }
    return true;
}

void populateAccount(Account arr[], int &currNumOfAccounts, int size){ // Populates the array of type Account
    if (size <= currNumOfAccounts) {
        cout << "Cannot execute, array is full" << endl;
        cout << endl;
        return;
    }
    string accountNumber = "";
    int numOfAttempts = 0; // Counts the number of Attempts
    cout << "Enter account number: ";
    getline(cin, accountNumber);
    numOfAttempts++;
    while(true) { //Input Validation

        if (isNumber(accountNumber) && stoi(accountNumber) > 0) {
            break;
        } else {
            cout << "Invalid value, please reenter: ";
            getline(cin, accountNumber);
            numOfAttempts++;
            if (numOfAttempts == 5) {
                cout << "Too many unsuccessful attempts, exiting";
                exit(EXIT_FAILURE);
            }
        }
    }
    string balance = "";
    numOfAttempts = 0; // Reset number of Attempts to use again.
    cout << "Enter balance: ";
    getline(cin, balance);
    while(true){ //Input Validation
        if(isDecimalNumber(balance) && stod(balance) > 0){
            break;
        } else {
            cout << "Invalid value, please reenter: ";
            getline(cin, balance);
            numOfAttempts++;
            if (numOfAttempts == 5) {
                cout << "Too many unsuccessful attempts, exiting";
                exit(EXIT_FAILURE);
            }
        }
    }
    string name;
    string address;
    cout << "Enter owner's name: ";
    getline(cin,name);
    cout << "Enter owner's address: ";
    getline(cin,address);

    cout << endl;

    arr[currNumOfAccounts].accountNumber = stoi(accountNumber);
    arr[currNumOfAccounts].balance = stod(balance);
    arr[currNumOfAccounts].ownerInfo.name = name;
    arr[currNumOfAccounts].ownerInfo.address = address;
    currNumOfAccounts++;

}




void printAccount(const Account& myVariable){ // Prints the one account

    cout << "Account #: " << myVariable.accountNumber << endl;
    cout << "Owner's name: " << myVariable.ownerInfo.name << endl;
    cout << "Owner's address: " << myVariable.ownerInfo.address << endl;
    cout << "Balance: " << myVariable.balance << endl;
}

void linearSearch2ndOption(Account arr[], int numElems){ // Does Linear Search when option 2 is selected.
    bool Found = false;
    string accountNumber = "";
    int numberOfAttempts = 0; // Initialize number of Attempts to count how many attempts.
    cout << "Enter account number: ";
    getline(cin, accountNumber);
    numberOfAttempts++;
    while(numberOfAttempts != 5) { // Input Validation

        if (isNumber(accountNumber) && stoi(accountNumber) > 0) {
            break;
        } else {
            cout << "Invalid value, please reenter: ";
            getline(cin, accountNumber);
            numberOfAttempts++;
            if (numberOfAttempts == 5) {
                cout << "Too many unsuccessful attempts, exiting" << endl;
                exit(EXIT_FAILURE);
            }
        }
    }
    int i;
    for(i = 0; i < numElems; i++){ // Loops through the array
        if (arr[i].accountNumber == stoi(accountNumber)){ // If the account number is equal to eh user inputted account number, then print the information related to that account
            printAccount(arr[i]);
            Found = true;
            break;
        }
    }
    if (!Found){ // If account is not found, then display "Account not found"
        cout << "Account not found" << endl;
    }
    cout << endl;
}

int main() {
    //Prompt the user to enter the maximum number of Accounts
    string numOfAccounts = "";

    //Number of Attempts
    int numOfAttempts1 = 0;
    cout << "Enter max number of accounts: ";
    getline(cin,numOfAccounts);
    numOfAttempts1++;
    while(numOfAttempts1 != 5) { // Input Validation

        if (isNumber(numOfAccounts) && stoi(numOfAccounts) > 0) {
            break;
        } else {
            cout << "Invalid value, please reenter: ";
            getline(cin, numOfAccounts);
            numOfAttempts1++;
            if (numOfAttempts1 == 5) {
                cout << "Too many unsuccessful attempts, exiting";
                exit(EXIT_FAILURE);
            }
        }
    }

    cout << endl;

    int currNumOfAccounts = 0;
    Account* bankAccount = new Account[stoi(numOfAccounts)]; // Dynamically allocates an array of Accounts of the size entered by the user

    // Create menu
    string menuChoice = "";
    int numOfAttempts2 = 0;
    bool run = true;
    while(run) // While run == true, the menu will keep repeating
    {
        cout << "Menu:" << endl;
        cout << "1->Enter data for specific account, 2->Display data for specific account" << endl;
        cout << "3->Display data for all accounts  , 4->Quit:" << endl;
        getline(cin,menuChoice);
        numOfAttempts2++;
        while(numOfAttempts2 != 5) {

            if (isNumber(menuChoice) && (stoi(menuChoice) > 0 && stoi(menuChoice) < 5)) {
                break;
            } else {
                cout << "Invalid choice, please reenter: ";
                getline(cin, numOfAccounts);
                numOfAttempts2++;
            }
            if (numOfAttempts2 == 5) {
                cout << "Too many unsuccessful attempts, exiting";
                exit(EXIT_FAILURE);
            }
        }
        if (numOfAttempts2 == 5) {
            break;
        }

        if(stoi(menuChoice) == 4) // Exits the menu
        {
            run = false;
        }
        if(stoi(menuChoice) == 1) // Asks user for input on what to populate the account with
        {
            populateAccount(bankAccount,currNumOfAccounts, stoi(numOfAccounts));
        }
        if(stoi(menuChoice) == 2) // After user enters correct input for account number, displays information related to the account
        {
            linearSearch2ndOption(bankAccount,stoi(numOfAccounts));
        }
        if(stoi(menuChoice) == 3){ // Displays all information for all accounts
            for (int i = 0; i < currNumOfAccounts; i++){
                printAccount(bankAccount[i]);
            }
            cout << endl;
        }
    }

    return 0;
}
