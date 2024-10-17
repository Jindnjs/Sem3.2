//
//  main.cpp
//  Week7Train
//
//  Created by 유진원 on 10/16/24.
//

#include <iostream>
#include <string>
#include "Circle2D.hpp"

int main(int argc, const char * argv[]) {
    // insert code here...
    
    //반지름 문자 예외처리
    Circle2D e({1,3}, 3);
    e.setRadius(-2);
    Circle2D e2(e);
    
    std::cout << "e반지름 : " << e.getRadius() << std::endl;
    std::cout << "e2반지름 : " << e2.getRadius() << std::endl;
    std::cout << "eC : " << e.getCenter().x<<" "<<e.getCenter().y << std::endl;
    std::cout << "e2C : " << e2.getCenter().x<<" "<<e2.getCenter().y << std::endl;
    
    
    e.pointPrint();
    e2.pointPrint();
    //
//    char * a = new char[10];
//    strcpy(a, "1df");
//    Circle2D c({1,2}, a[0]);
//    c.pointPrint();
//    
//    std::cout << c.getRadius() << std::endl;
//    std::cout << std::isdigit(a[0]) << std::endl;
//    
    
    //std::cout << a.x << " " << a.y << std::endl;
    
    
    return 0;
}
