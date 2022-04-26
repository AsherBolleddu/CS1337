//
// Created by Asher Bolleddu on 4/25/2022.
//

#include <string>
#include "Date.h"
#include "Account.h"

using namespace std;

Account::Account(string nam, double bal, Date d) {
    ownerName = nam;
    balance = bal;
    accountNumber = numberAccounts + 1000;
    numberAccounts++;
    transactionHistory = nullptr;
    numberTransactions = 0;
}

bool Account::withdraw(double amount, Date) {
    if(amount > 0 && balance >= amount){
        balance -= amount;
        return true;
    } else {
        return false;
    }
}

bool Account::deposit(double amount, Date) {
    if (amount > 0){
        balance += amount;
        return true;
    } else {
        return false;
    }
}

int Account::getAccountNumber() const {
    return accountNumber;
}

double Account::getBalance() const {
    return balance;
}

int Account::getNumberAccounts() {
    return numberAccounts;
}

void Account::print() const {
    cout << "#: " << accountNumber << ", Name: " << ownerName << ", Balance: " << balance << " Galactic units" << endl;
}
