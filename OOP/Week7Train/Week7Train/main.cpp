//
//  main.cpp
//  Week7Train
//
//  Created by 유진원 on 10/16/24.
//

#include <iostream>

#include "Circle2D.hpp"

int main(int argc, const char * argv[]) {
    // insert code here...
    Point2D center = {4,5};
    
    std::cout << center.x << " " << center.y << std::endl;
    
    Circle2D c(center, 5);
    
    std::cout << c.getRadius() << std::endl;
    std::cout << c.getCenter().y << std::endl;
    
    return 0;
}
