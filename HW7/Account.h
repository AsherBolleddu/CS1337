//
// Created by Asher Bolleddu on 4/2/2022.
//
#ifndef HW7_ACCOUNT_H
#define HW7_ACCOUNT_H
#include <string>

using namespace std;



struct Date
{
    int month;
    int day;
    int year;
};

struct Person // stores account owner’s info
{
    string name;
    Date DOB;
    string address;
};

class Account{
private:
    int accountNumber;
    int numOwners;
    Person * ownerPtr;
    double balance;
    static int accountCounter;
public:
    Account(int , double);
    ~Account();
    int withdraw(double);
    int deposit(double);
    void setOwner(int , Person);
    Person getOwner(int) const;
    int getAccountNumber() const;
    double getBalance() const;
    int getNumOwners() const;
};


#endif //HW7_ACCOUNT_H
