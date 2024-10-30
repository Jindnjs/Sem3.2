//
//  main.cpp
//  Week8Train
//
//  Created by 유진원 on 10/30/24.
//
#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include "Shape2D.h"
#include "Point2D.h"
#include "Rect2D.h"
#include "Square2D.h"
#include "Ellipse2D.h"
#include "Circle2D.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    Point2D center = {0,0};
    Shape2D *s[10] ;
    
    s[0] = new Rect2D(center, 4,5);
    std::cout << s[0] -> get_area();
    std::cout << s[0] -> get_name();
    
    
    return 0;
}

// Rect2D(center ,width, height
//Ellipse center major minor
//Squeare center side
//Circle center, radius
