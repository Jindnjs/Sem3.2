//
//  Circle.hpp
//  Week6Prac
//
//  Created by 유진원 on 10/16/24.
//

#ifndef Circle_hpp
#define Circle_hpp

#include <stdio.h>

class Circle{
private:
    double radius;
    int *arr;
public:
    //Constructor
    Circle();
    Circle(double);
    Circle(const Circle &);
    ~Circle();
    
    
    double getRadius() const;
    double getArea() const;
    double getPerimeter() const;
    
    int *getArr() const;
    
    void setRaidus(double);
}
;
#endif /* Circle_hpp */
