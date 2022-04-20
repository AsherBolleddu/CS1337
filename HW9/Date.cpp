//
// Created by Asher Bolleddu on 4/18/2022.
//

#include <iostream>
#include <string>
#include "Date.h"

using namespace std;

string Date::monthName[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

void Date::set(int month_, int day_, int year_, int hour_) { // mutator that sets the variables month, day, year, and hour to the parameter values
    month = month_;
    day = day_;
    year = year_;
    hour = hour_;
}

bool Date::operator<(const Date &rhs) { // compares if the first date is less than the second date
    int totalDaysInMonth [] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
    int n1 = (365*((this->year)-1)+totalDaysInMonth[(this->month)-1]+this->day)*24+this->hour;
    int n2 = (365*((rhs.year)-1)+totalDaysInMonth[(rhs.month)-1]+rhs.day)*24+rhs.hour;
    if (n1-n2 < 0){
        return true;
    }
    return false;
}

void Date::print() const { // Prints everything
    cout << monthName[month-1] << " " << day <<", " << year << ", " << hour << ":00";
}

int Date::getMonthFromDate() const {
    return month;
}

int Date::getDayFromDate() const {
    return day;
}

int Date::getYearFromDate() const {
    return year;
}

int Date::getHourFromDate() const {
    return hour;
}