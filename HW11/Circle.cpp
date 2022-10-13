//
// Created by Asher Bolleddu on 4/30/2022.
//
#include "BasicShape.h"
#include "Circle.h"

double areaOfCircle;

Circle::Circle(double x, double y, double rad) {
    if (x < 0){
        centerX  = x;
        throw NegativeValue();
    } else if (y < 0){
        centerY = y;
        throw NegativeValue();
    } else if (rad < 0){
        radius = rad;
        throw NegativeValue();
    } else {
        centerX = x;
        centerY = y;
        radius = rad;
        calcArea();
        setArea(areaOfCircle);
    }
}

double Circle::calcArea() const {
    areaOfCircle = radius * radius * 3.14159;
    return areaOfCircle;
}