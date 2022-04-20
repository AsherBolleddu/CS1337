//
// Created by Asher Bolleddu on 4/10/2022.
//

#include <iostream>
#include <string>
#include "Date.h"

using namespace std;

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

bool Date::operator==(const Date &rhs) { // compares if the first date is equal to the second date
    if ((this->month == rhs.month) && (this->day == rhs.day) && (this->year == rhs.year) && (this->hour == rhs.hour)){
        return true;
    } else{
        return false;
    }
}

bool Date::operator<=(const Date &rhs) { // compares if the first date is less than or equal to the second date
    int totalDaysInMonth [] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
    int n1 = (365*((this->year)-1)+totalDaysInMonth[(this->month)-1]+this->day)*24+this->hour;
    int n2 = (365*((rhs.year)-1)+totalDaysInMonth[(rhs.month)-1]+rhs.day)*24+rhs.hour;
    if (n1-n2 <= 0){
        return true;
    }
    return false;
}

int Date::operator-(const Date &rhs) { // returns the number of hours elapsed from d1 to d2.
    int totalDaysInMonth [] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
    int n1 = (365*((this->year)-1)+totalDaysInMonth[(this->month)-1]+this->day)*24+this->hour;
    int n2 = (365*((rhs.year)-1)+totalDaysInMonth[(rhs.month)-1]+rhs.day)*24+rhs.hour;

    return n1 - n2;
}

void Date::print() { // Prints everything
    string months [] = {"January","February","March","April","May","June","July","August","September","October","November","December"};
    cout << months[month-1] << " " << day <<", " << year << ", " << hour << ":00";
}