//
//  Circle2D.cpp
//  Week8Train
//
//  Created by 유진원 on 10/30/24.
//

#include "Circle2D.h"

Circle2D::Circle2D(Point2D center, int radius):Ellipse2D(center, 2*radius, 2*radius){}
Circle2D::~Circle2D(){}

const std::string Circle2D::get_name() const{
    return "this is Circle2D";
}
