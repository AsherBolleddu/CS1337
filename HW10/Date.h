//
// Created by Asher Bolleddu on 4/25/2022.
//

#ifndef HW10_DATE_H
#define HW10_DATE_H
#include <iostream>
using namespace std;

class Date
{
private:
    int month, day, year, hour; // Hour in military time
    // int calcElapsedTime(Date d); // I implemented this private member function, but you are not required to implement it

public:
    void set(int month_, int day_, int year_, int hour_);
    int getMonth() const;
    int getDay() const;
    int getYear() const;
    int getHour() const;
    void print() const;
};

#endif //HW10_DATE_H
