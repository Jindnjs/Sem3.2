//
//  main.cpp
//  Week6Prac
//
//  Created by 유진원 on 10/16/24.
//

#include <iostream>

#include "Circle.hpp"
int main(int argc, const char * argv[]) {
    // insert code here...
    Circle c;
    
    c.setRaidus(0.1);
    
    std::cout << c.getArea() << std::endl;
    
    return 0;
}
