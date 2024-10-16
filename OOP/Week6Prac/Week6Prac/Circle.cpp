//
//  Circle.cpp
//  Week6Prac
//
//  Created by 유진원 on 10/16/24.
//

#include "Circle.hpp"

#define _USE_MATH_DEFINES
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <iostream>
 
double Circle::getRadius() const{
    return radius;
}

double Circle::getArea() const{
    return radius*radius*M_PI;
}

double Circle::getPerimeter() const{
    return 2*radius*M_PI;
}

int * Circle::getArr() const{
    return arr;
}
void Circle::setRaidus(double value){
    this->radius = value;
}

//Circle::Circle(){
//    radius = 0;
//}

Circle::Circle() : radius(0){
    arr = (int*)malloc(sizeof(int) * 5);
}
Circle::Circle(double value) : radius(value){
    arr = (int*)malloc(sizeof(int) * 5);
}
Circle::Circle(const Circle &circle) {
    
    arr = (int*)malloc(sizeof(int) * 5);
    std::memcpy(arr, circle.getArr(), sizeof(int) * 5);
    
    radius = circle.getRadius();
}
Circle::~Circle(){
    free(arr);
}
