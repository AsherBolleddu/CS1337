//
// Created by Asher Bolleddu on 4/18/2022.
//

#ifndef HW9_DATE_H
#define HW9_DATE_H
#include <string>
#include <iostream>
using namespace std;

//// Date
class Date
{
private:
    int month, day, year, hour;
    static string monthName[13];
    int calcElapsedDay(Date d); // You are not required to implement this private function

public:
    void set(int month_, int day_, int year_, int hour_);
    bool operator<(const Date & rhs);
    void print() const;
    int getMonthFromDate() const;
    int getDayFromDate() const;
    int getYearFromDate() const;
    int getHourFromDate() const;
};

#endif //HW9_DATE_H
