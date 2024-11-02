//
//  Square2D.cpp
//  Week8Train
//
//  Created by 유진원 on 10/30/24.
//

#include "Square2D.h"

Square2D::Square2D(Point2D center, int side) : Rect2D(center,side,side){}
const std::string Square2D::get_name() const{
    return "this is Square2D";
}
Square2D::~Square2D(){
    
}

