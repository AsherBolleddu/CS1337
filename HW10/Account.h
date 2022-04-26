//
// Created by Asher Bolleddu on 4/25/2022.
//

#ifndef HW10_ACCOUNT_H
#define HW10_ACCOUNT_H
#include <string>
#include "Date.h"
using namespace std;

struct Transaction
{
    Date date;
    int transactionType; // 0, 1, 2 for account creation, deposit and withdrawal respectively
    double amount;
};

class Account
{
private:
    int accountNumber;
    string ownerName;

protected:
    double balance;
    static int numberAccounts;
    Transaction * transactionHistory; // Place holder for Extra credit
    int numberTransactions; // Place holder for Extra credit
#ifdef EXTRA_CREDIT
    void recordTransaction(Transaction transact); // Extra credit
#endif

public:
    Account(string nam, double bal, Date d);
    virtual bool withdraw(double, Date);
    bool deposit(double, Date);
    int getAccountNumber() const;
    double getBalance() const;
    static int getNumberAccounts();
#ifdef EXTRA_CREDIT
    void printTransactions() const;
#endif
    virtual void print() const;

};

#endif //HW10_ACCOUNT_H
