//
//  Rect2D.cpp
//  Week8Train
//
//  Created by 유진원 on 10/30/24.
//

#include "Rect2D.h"

Rect2D::Rect2D (Point2D center, int width, int height)
:center(center), width(width), height(height)
{
    if (width < 0){
        this->width = 1;
    }
    if (height <0){
        this->height = 1;
    }
}
const Point2D* Rect2D::get_perimeter_points() const{
    return this->perimeterPoints;
}
const std::string Rect2D::get_name() const{
    return "this is Rect2D";
}
Point2D Rect2D::get_center() const{
    return this->center;
}
double Rect2D::get_area() const{
    return width*height;
}
