//
// Created by Asher Bolleddu on 4/18/2022.
//

#include <iomanip>
#include <string>
#include "Date.h"
#include "Account.h"

using namespace std;

Account::Account() {
    accountNumber = 0;
    numOwners = 0;
    ownerPtr = nullptr;
    balance = 0;
    numTransactions = 0;
    transacPtr= nullptr;

}

void Account::setAccount(int accountNumber_, int numOwners_) {
    accountNumber = accountNumber_;
    numOwners = numOwners_;
    ownerPtr = new Person[numOwners];
    balance = 0;
}

void Account::setOwner(int ind, Person p) {
    ownerPtr[ind] = p;
}

Person Account::getOwner(int ind) const { // gets the Owner
    return ownerPtr[ind];
}

int Account::getAccountNumber() const { // gets the accountNumber
    return accountNumber;
}

int Account::getNumOwners() const { // gets the Number of Owners
    return numOwners;
}

void Account::setTransacPtr(Transaction *transacPtr_) {
    transacPtr = transacPtr_;
}

int Account::getNumTransactions() const {
    return numTransactions;
}

void Account::setNumTransactions(int numTransactions_) {
    numTransactions = numTransactions_;
}

Transaction Account::getTransaction(int ind) const {
    return transacPtr[ind];
}

