//
// Created by Asher Bolleddu on 4/25/2022.
//
#include "Account.h"
#include "Date.h"
#include "PremiumAccount.h"

const double PremiumAccount::MIN_BALANCE = 1000;

PremiumAccount::PremiumAccount(string nam, double amnt, Date d) : Account(nam,amnt, d){}

bool PremiumAccount::withdraw(double amnt, Date d) {
    if(balance >= (amnt + MIN_BALANCE)){
        balance -= amnt;
        return true;
    } else {
        return false;
    }
}

double PremiumAccount::getMinBalance() {
    return MIN_BALANCE;
}

void PremiumAccount::print() const {
    cout << "Premium Account , "; this -> Account::print();
}