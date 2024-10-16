//
//  Circle2D.hpp
//  Week7Train
//
//  Created by 유진원 on 10/16/24.
//

#ifndef Circle2D_hpp
#define Circle2D_hpp

#include <stdio.h>
#include "Point2D.hpp"

class Circle2D{
private:
    //멤버변수
    struct Point2D center;
    int radius;
    Point2D *perimeterPoints;
    
    //내부 함수
    int calcPoints();
    void setPermeterPoints();
    
public:
    //Constructor
    Circle2D(Point2D, int);
    Circle2D(const Circle2D &);
    ~Circle2D();
    
    //getter
    Point2D getCenter() const;
    int getRadius() const;
    const Point2D * getPerimeterPoints() const;
    
    //setter
    void setCenter(Point2D);
    void setRadius(int);
    
};
#endif /* Circle2D_hpp */
