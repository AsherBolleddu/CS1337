//
// Created by Asher Bolleddu on 4/25/2022.
//

#include "Account.h"
#include "RegularAccount.h"

using namespace std;

RegularAccount::RegularAccount(string nam, double amnt, Date d) : Account(nam,amnt,d) {}

void RegularAccount::print() const {
    cout << "Regular Account , "; this -> Account::print();
}