//
// Created by Asher Bolleddu on 4/30/2022.
//

#include "BasicShape.h"
#include "Rectangle.h"

double areaOfARectangle;

Rectangle::Rectangle(double w, double l) {
    if (w < 0){
        width = w;
        throw NegativeValue();
    } else if (l < 0){
        length = l;
        throw NegativeValue();
    } else {
        width = w;
        length = l;
        calcArea();
        setArea(areaOfARectangle);
    }
}

double Rectangle::calcArea() const {
    areaOfARectangle = width * length;
    return areaOfARectangle;
}