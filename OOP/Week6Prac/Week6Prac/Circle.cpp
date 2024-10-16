//
//  Circle.cpp
//  Week6Prac
//
//  Created by 유진원 on 10/16/24.
//

#include "Circle.hpp"

#define _USE_MATH_DEFINES
#include <cmath>
 
double Circle::getRadius() const{
    return radius;
}

double Circle::getArea() const{
    return radius*radius*M_PI;
}

double Circle::getPerimeter() const{
    return 2*radius*M_PI;
}

void Circle::setRaidus(double value){
    radius = value;
}
