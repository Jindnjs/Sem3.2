//
//  Rect2D.hpp
//  Week8Train
//
//  Created by 유진원 on 10/30/24.
//

#ifndef Rect2D_hpp
#define Rect2D_hpp

#include "Shape2D.h"
#include "Point2D.h"

class Rect2D : public Shape2D{
    
private:
    Point2D center;
    int width;
    int height;
    Point2D *perimeterPoints;
    void calc();
public:
    Rect2D (Point2D,int,int);
    ~Rect2D();
    const Point2D* get_perimeter_points() const;
    const std::string get_name() const;
    Point2D get_center() const;
    double get_area() const;
    int get_num_of_points() const;
};


#endif /* Rect2D_hpp */
