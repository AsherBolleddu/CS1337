//
// Created by Asher Bolleddu on 4/25/2022.
//

#ifndef HW10_REGULARACCOUNT_H
#define HW10_REGULARACCOUNT_H
#include "Account.h"
class RegularAccount : public Account
{
public:
    RegularAccount(string nam, double amnt, Date d);
    void print() const override;
};

#endif //HW10_REGULARACCOUNT_H
