//
// Created by Asher Bolleddu on 4/2/2022.
//

#include <string>
#include "Account.h"

using namespace std;

int Account::accountCounter = 1000;

Account::Account(int numberOwners, double amount){ // Constructor
    accountNumber = accountCounter;
    numOwners = numberOwners;
    ownerPtr = new Person[numOwners];
    balance = amount;
    accountCounter++;
}

Account::~Account() { // Destructor
    delete[] ownerPtr;
}

int Account::withdraw(double amount) { // Withdraw function
    if (amount > 0 && balance >= amount){
        balance -= amount;
        return 0;
    } else{
        return 1;
    }
}

int Account::deposit(double amount) { // Deposit function
    if (amount > 0){
        balance += amount;
        return 0;
    } else{
        return 1;
    }
}

void Account::setOwner(int ind, Person p) { // sets the Owner
    ownerPtr[ind] = p;
}

Person Account::getOwner(int ind) const { // gets the Owner
    return ownerPtr[ind];
}

int Account::getAccountNumber() const { // gets the accountNumber
    return accountNumber;
}

double Account::getBalance() const { // gets the Balance
    return balance;
}

int Account::getNumOwners() const { // gets the Number of Owners
    return numOwners;
}