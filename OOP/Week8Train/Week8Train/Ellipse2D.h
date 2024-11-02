//
//  Ellipse2D.hpp
//  Week8Train
//
//  Created by 유진원 on 10/30/24.
//

#ifndef Ellipse2D_hpp
#define Ellipse2D_hpp

#include "Point2D.h"
#include "Shape2D.h"

class Ellipse2D:public Shape2D{
private:
    struct Point2D center;
    int major;
    int minor;
    Point2D *perimeterPoints;
    void calc();
public:
    Ellipse2D(Point2D,int,int);
    ~Ellipse2D();
    const Point2D* get_perimeter_points() const ;
    const std::string get_name() const;
    Point2D get_center() const;
    double get_area() const;
    int get_num_of_points() const;
};

#endif /* Ellipse2D_hpp */
