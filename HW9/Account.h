//
// Created by Asher Bolleddu on 4/18/2022.
//

#ifndef HW9_ACCOUNT_H
#define HW9_ACCOUNT_H
#include "Date.h"
//// Account

struct Transaction
{
    Date transactionDate;
    int type;
    double amount;
};

struct Person
{
    string name;
    Date DOB;
    string address;

};

class Account
{
private:
    int accountNumber;
    int numOwners;
    Person * ownerPtr;
    double balance;
    int numTransactions;
    Transaction * transacPtr;


public:
    Account();
    void setAccount(int accountNumber_, int numOwners_); //
    void setOwner(int ind, Person p); //
    Person getOwner(int ind) const; //
    int getAccountNumber() const; //
    int getNumOwners() const; //
    void setTransacPtr(Transaction * transacPtr_); //
    int getNumTransactions() const; //
    void setNumTransactions(int numTransactions_); //
    Transaction getTransaction(int ind) const; //
};

#endif //HW9_ACCOUNT_H
