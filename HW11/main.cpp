#include <iostream>
#include "BasicShape.h"
#include "Circle.h"
#include "Rectangle.h"
#include <string>

using namespace std;

int main() {
    double x, y, radius;

    cout << "================= Circle =================" << endl;

    bool validCircle = false;
    while(!validCircle){
        cout << "Please enter the x coordinate of the circle's center: ";
        cin >> x;
        cout << "Please enter the y coordinate of the circle's center: ";
        cin >> y;
        cout << "Please enter the radius of the circle: ";
        cin >> radius;

        try{
            Circle circle(x,y,radius);
            cout << "***** The area of the circle is " << circle.getArea() << ".";
            validCircle = true;
        } catch (Circle::NegativeValue){
            cout << "***** Negative input value" << endl;
            cout << endl;
        }
    }

    double width, length;

    cout << "================= Rectangle =================" << endl;

    bool validRectangle = false;
    while(!validRectangle){
        cout << "Please enter the length of the rectangle: ";
        cin >> length;
        cout << "Please enter the width of the rectangle: ";
        cin >> width;
        try{
            Rectangle rectangle(length,width);
            cout << "***** The area of the rectangle is " << rectangle.getArea() << ".";
            validRectangle = true;
        } catch (Rectangle::NegativeValue){
            cout << "***** Negative input value" << endl;
            cout << endl;
        }
    }
    return 0;
}
