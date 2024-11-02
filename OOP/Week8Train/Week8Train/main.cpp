//
//  main.cpp
//  Week8Train
//
//  Created by 유진원 on 10/30/24.
//
#define _USE_MATH_DEFINES

#include <cmath>
#include <iostream>
#include <string>

#include "Shape2D.h"
#include "Point2D.h"
#include "Rect2D.h"
#include "Square2D.h"
#include "Ellipse2D.h"
#include "Circle2D.h"

void PrintSpec(Shape2D *s);

int main(int argc, const char * argv[]) {
    // insert code here...
    Point2D center = {4,3};
    Shape2D *s [12] ;
    
    s[0] = new Rect2D(center, 1,1);
    
    s[1] = new Rect2D(center, 7,4);

    s[2] = new Rect2D(center, 12,13);

    s[3] = new Rect2D(center, 8,6);
    
    s[4] = new Square2D({2,2},5);
    
    s[5] = new Square2D({4,7}, 6);
    
    s[6] = new Ellipse2D(center, 8, 3);
    
    s[7] = new Ellipse2D(center, 4, 10);
    
    s[8] = new Ellipse2D(center, 9, 4);
    
    s[9] = new Ellipse2D(center, 5, 7);
    
    s[10] = new Circle2D(center, 6);
    s[11] = new Circle2D(center, 7);
    
    for(int i =0;i<12;i++){
        PrintSpec(s[i]);
        delete s[i];
    }
    
    return 0;
}

// Rect2D(center ,width, height
//Ellipse center major minor
//Squeare center side
//Circle center, radius

void PrintSpec(Shape2D *s){
    std::cout<< "===================" <<std::endl;
    std::cout<< s-> get_name() << std::endl;
    std::cout<< "center is : (" << s->get_center().x <<
    ", "<<s->get_center().y << ")" << std::endl;
    std::cout<< "Area is : " << s->get_area()<<std::endl;
    std::cout<< "Num of Point is : " << s->get_num_of_points()<<std::endl;
    std::cout<< "PerimiterPoints" <<std::endl;
    for (int i = 0; i<s->get_num_of_points(); i++){
        std::cout << "("<<s->get_perimeter_points()[i].x << ", " << s->get_perimeter_points()[i].y << ")";
            if ((i + 1) % 10 == 0) {
                std::cout << std::endl;
            }
    }
    std::cout<<std::endl;
}
