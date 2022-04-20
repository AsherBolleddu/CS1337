/*
Author: Asher Bolleddu
Compiler: GNU GCC
Date: 04/19/2022

Purpose of program: Your program should determine the number of account records in the file, dynamically create an array of Account of size equal to the
 number of account records (note this is an array of Account, not an array of pointers to Account), and populate the array with the data read
 from the file. Finally it should display for each account, the owner’s data and the transactions data.
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include "Date.h"
#include "Account.h"

using namespace std;


/* This function takes as argument a string representing a date
in the mm/dd/yyyy/hh format and returns the month as an int
The argument string is assumed properly formatted and no input validation
is required
*/
int getMonthFromString(string d)
{
    return stoi(d.substr(0,2));
}

/* This function takes as argument a string representing a date
in the mm/dd/yyyy/hh format and returns the day as an int
The argument string is assumed properly formatted and no input validation
is required
*/
int getDayFromString(string d)
{
    return stoi(d.substr(3,2));
}

/* This function takes as argument a string representing a date
in the mm/dd/yyyy/hh format and returns the year as an int
The argument string is assumed properly formatted and no input validation
is required
*/
int getYearFromString(string d)
{
    return stoi(d.substr(6,4));
}

/* This function takes as argument a string representing a date
in the mm/dd/yyyy/hh format and returns the hour as an int
The argument string is assumed properly formatted and no input validation
is required
*/
int getHourFromString(string d)
{
    return stoi(d.substr(11,2));
}

/* This function reads from an account file and populates an array of Account objects
 * (not an array of pointers to Account) with all the owners and transactions data read from the file.
 * The owner data is the owner’s name, DOB and address.
 * The transaction data is the transaction date, transaction type (account creation, deposit, withdrawal),
 * and transaction amount. For each account, the function should dynamically allocate an array of
 * Transaction of size equal to the number of transactions, assign the array’s address to transacPtr,
 * and populate the array with the transaction data. In the extra credit version, after the array
 * has been populated, this function should sort the transactions array by date (oldest first).
It takes as arguments the file name, the array and the size of the array.
It returns true if file open is successful, false otherwise. It should close the file when done
*/

int getNumberOfAccounts(string fname) { // Getting the number of records
    ifstream readFile;
    readFile.open(fname);
    std::stringstream buffer;
    buffer << readFile.rdbuf();

    string data = buffer.str();

    int count = 0;
    int i = 0;
    for ( ;(i = data.find('#', i)) != std::string::npos; i++) {
        count++;
    }
    return count;
}

static vector<string> split(const string &s, char delim) {
    vector<string> res;
    stringstream ss(s);
    string item;

    while(getline(ss,item,delim)) {
        res.push_back(item);
    }
    return res;
}

void sortTransactionsByDate(Transaction * t, int n) { // Bubble sort
    for(int i=0;i<n;i++) {
        for(int j=i+1;j<n;j++) {
            if(!(t[i].transactionDate < t[j].transactionDate)) {
                Transaction temp = t[i];
                t[i] = t[j];
                t[j] = temp;
            }
        }
    }
}

bool readAccounts(string fname, Account  accntPtr [], int numAccnts)
{
    // Open the file, check for open failure/success
    ifstream readFile;
    readFile.open(fname);
    if(!readFile){
        return false;
    } else {
        std::stringstream buffer;
        buffer << readFile.rdbuf();

        string data = buffer.str();

        vector<int> pos;
        int i = 0;
        for ( ;(i = data.find('#', i)) != std::string::npos; i++) {
            pos.push_back(i);
        }
        pos.push_back(i);


        vector<string> details;
        for(int i=0;i<pos.size()-1;i++) {
            details.push_back(data.substr(pos[i] + 1, pos[i+1] - 1));
        }


        for (int accntIndex = 0; accntIndex < numAccnts; accntIndex++)  // Loop over the accounts
        {
            // read from the file the various data items related to the account, up to numOwners
            // Call the setAccount() member function to set the relevant member variables of the account
            vector<string> accountDetail = split(details[accntIndex],'\n');
            int i = 0;
            accntPtr[accntIndex].setAccount(stoi(accountDetail[1]), stoi(accountDetail[2]));
            int numOwners = stoi(accountDetail[2]);
            for (int ownerIndex = 0; ownerIndex < numOwners; ownerIndex++) // Loop over the owners for Account at accntIndex
            {
                // read the owner’s name, DOB and address, perform the necessary conversions
                // Use the appropriate setter to set the owner at ownerIndex
                vector<string> dateDetails = split(accountDetail[ownerIndex*3+4], '/');
                Date d;
                d.set(stoi(dateDetails[0]), stoi(dateDetails[1]), stoi(dateDetails[2]), stoi(dateDetails[3]));
                struct Person p{accountDetail[ownerIndex*3+3], d, accountDetail[ownerIndex*3+5]};
                accntPtr[accntIndex].setOwner(ownerIndex, p);

            }
            // read numTransactions
            // dynamically allocate an array of Transactions of the right size, and assign address to transactionPtr

            int numTransactions = stoi(accountDetail[3 + numOwners *3]);
            accntPtr[accntIndex].setNumTransactions(numTransactions);

            struct Transaction *t = new Transaction[numTransactions];
            for (int transac = 0; transac < numTransactions; transac++) // loop over the transactions for Account at accntIndex
            {
                // Read date from file, perform the appropriate conversions and set the transaction date
                // Read type, amount and set the transaction type and amount
                vector<string> tranDetails = split(accountDetail[numOwners *3 + 4 + transac], ' ');
                vector<string> dateDetails = split(tranDetails[0], '/');
                Date d;
                d.set(stoi(dateDetails[0]), stoi(dateDetails[1]), stoi(dateDetails[2]), stoi(dateDetails[3]));
                t[transac] = {d, stoi(tranDetails[1]), stod(tranDetails[2])};
            }
            sortTransactionsByDate(t, numTransactions);
            accntPtr[accntIndex].setTransacPtr(t);
            // Use the appropriate setter to set transacPtr with transactionPtr
            // Call the function to sort the transaction array by date, oldest date first (extra credit version only)
        } // end of loop over accounts
        // Close the file
        readFile.close();
    }
    return true;
}

int main() {
    /* Determine the number of account records in the file
     * Dynamically create an array of Account of size equal to the number of accounts, to hold
     * the Account objects (note this is an array of Account, not an array of pointers to Account)
     * Call readAccounts to read data from the file and populate the array of Accounts.
     * Read the populated array of Accounts to display for each account the account number, along
     * with the data for all the owners, and the data for all the transactions. The owner data is
     * the owner’s name, DOB and address. The transaction data is the transaction date,
     * transaction type (account creation, deposit, withdrawal), and transaction amount.
     * Additionally, the new balance resulting from each transaction is displayed. In the extra
     * credit, the transactions should be listed by date, the oldest transaction being listed first.*/

    string fileName;
    cout<<"Enter the account file name: ";
    cin>>fileName;
    int numAccounts = getNumberOfAccounts(fileName);
    Account * accounts = new Account[numAccounts];
    readAccounts(fileName, accounts, numAccounts);
    cout<<"There are "<< numAccounts <<" accounts in the file" << endl << endl << endl;

    map<int, double> accountBalance;
    string types[3] = {"account creation", "deposit", "withdrawal"};

    for(int i=0;i<numAccounts;i++) {
        cout<<"Account Number: "<<accounts[i].getAccountNumber()<<endl;
        cout<<"==============="<<endl;
        for(int j=0;j<accounts[i].getNumOwners();j++) {
            cout<<"Name: " << accounts[i].getOwner(j).name << ", DOB: " ;
            accounts[i].getOwner(j).DOB.print();
            cout << ", Address: " << accounts[i].getOwner(j).address << endl << endl;
        }
        cout << "Transaction history:"<< endl;
        cout << "--------------------" << endl;
        for(int j=0;j<accounts[i].getNumTransactions();j++) {
            if(accountBalance.count(accounts[i].getAccountNumber()) == 0) {
                accountBalance[accounts[i].getAccountNumber()] = 0;
            }
            if (accounts[i].getTransaction(j).type == 2 || accounts[i].getTransaction(j).type == 1) {
                accountBalance[accounts[i].getAccountNumber()] +=  accounts[i].getTransaction(j).amount;
            } else if (accounts[i].getTransaction(j).type == 3) {
                accountBalance[accounts[i].getAccountNumber()] -=  accounts[i].getTransaction(j).amount;
            }
            cout<<"Transaction #"<<j+1<<endl;
            cout<<"Date: " ;
            accounts[i].getTransaction(j).transactionDate.print();
            cout << ", type: " << types[accounts[i].getTransaction(j).type-1] << ", amount: "<< accounts[i].getTransaction(j).amount << ", new balance: " << accountBalance[accounts[i].getAccountNumber()] << endl;
            if (j != accounts[i].getNumOwners()-1 || i != numAccounts - 1){
                cout << endl;
            }
        }
    }
    return 0;
}
