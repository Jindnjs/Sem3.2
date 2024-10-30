//
//  Shape2D.h
//  Week8Train
//
//  Created by 유진원 on 10/30/24.
//


#ifndef Shape2D_h
#define Shape2D_h
#include "Point2D.h"
#include <string>

class Shape2D{
    
public:
    virtual const Point2D* get_perimeter_points() const = 0;
    virtual const std::string get_name() const = 0;
    virtual Point2D get_center() const =0;
    virtual double get_area() const =0;
};

#endif /* Shape2D_h */
