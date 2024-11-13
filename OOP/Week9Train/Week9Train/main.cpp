//
//  main.cpp
//  Week9Train
//
//  Created by 유진원 on 11/13/24.
//

#include <iostream>
#include "Vector2D.h"

void print(Vector2D& a){
    std::cout << "Vec("<<a.get_x() <<", "<<a.get_y()<<")"<<std::endl;
    
}
int main(int argc, const char * argv[]) {
    // insert code here...
    Vector2D a, b, c;
    a.set_x(3);a.set_y(3);
    b.set_x(3);b.set_y(3);
    print(a);
    std::cout << "Vec SIze = " << a.magnitude() << std::endl;
    std::cout << "Vec DotProd = " << a.dot_product(b)<< std::endl;
    std::cout << "Vec DotProd using * = " << a * b<< std::endl;
    c = a+b;
    std::cout << "C = ";
    print(c);
    std::cout << "C = ";
    c = a-b;
    print(c);
    
    std::cout << "+=Val = ";
    print(a += b);
    std::cout << "+=Val = ";
    print(a += b);
    std::cout << "-=Val = ";
    print(a -= b);
    
    (a += b + a)+= b;
    print(a);
    c = a - b;
    print(c);
    
    std::cout << "Vec DotProd = " << c.dot_product(b)<< std::endl;
    std::cout << "Vec DotProd = " << c * b << std::endl;
    
    return 0;
}

