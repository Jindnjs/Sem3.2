//
//  Ellipse2D.cpp
//  Week8Train
//
//  Created by 유진원 on 10/30/24.
//

#include "Ellipse2D.h"
#include <cmath>
void Ellipse2D::calc(){
    
    int idx = 0;
    
    int start = center.x - major/2;
    int end = center.x + major/2;
    
    double a = double(major)/2;
    double b = double(minor) /2;
    
    
    if (major % 2 == 0){
        perimeterPoints[idx++] = {start,center.y};
        start += 1;
        end -= 1;
    }
    
    for (int i = start; i <= end ; i ++ ){
        
        double k = pow(b,2) * (1 - pow(double(i - center.x) / a , 2));
        //std::cout<<i<<":"<<k<<"/" << sqrt(k) << "//";
        int y = round(double(center.y) + sqrt(k));
        //std::cout<<center.y<<"+"<<y<<std::endl; ;
        perimeterPoints[idx++] = {i,y};
        y = round(double(center.y) - sqrt(k));
        perimeterPoints[idx++] = {i,y};
        
    }
    if (major % 2 == 0)
        perimeterPoints[idx++] = {end + 1,center.y};
}

Ellipse2D::Ellipse2D(Point2D center, int major, int minor)
:center(center), major(major), minor(minor)
{
    if (major<=0)
        this->major = 1;
    if (minor<=0)
        this->minor = 1;
    
    this -> perimeterPoints = new Point2D[this->get_num_of_points()];
    calc();
}
Ellipse2D :: ~Ellipse2D(){
    delete this->perimeterPoints;
}
const Point2D* Ellipse2D::get_perimeter_points() const{
    return this->perimeterPoints;
}
const std::string Ellipse2D::get_name() const{
    return "this is Ellipse2D";
}
Point2D Ellipse2D::get_center() const{
    return this->center;
}
double Ellipse2D::get_area() const{
    return M_PI * major/2 * minor/2;
}
int Ellipse2D::get_num_of_points() const{
    return 2*major;
}

