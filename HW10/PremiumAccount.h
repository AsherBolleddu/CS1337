//
// Created by Asher Bolleddu on 4/25/2022.
//

#ifndef HW10_PREMIUMACCOUNT_H
#define HW10_PREMIUMACCOUNT_H
#include "Account.h"
#include "Date.h"

class PremiumAccount : public Account
{
private:
    static const double MIN_BALANCE;

public:
    PremiumAccount(string nam, double amnt, Date d);
    bool withdraw(double amnt, Date d) override;
    static double getMinBalance();
    void print() const override;

};

#endif //HW10_PREMIUMACCOUNT_H
