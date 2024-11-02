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
    if (width <= 0){
        this->width = 1;
    }
    if (height <= 0){
        this->height = 1;
    }
    
    if(Rect2D::get_num_of_points() == 0){
        this -> perimeterPoints = nullptr;
        return;
    }
        
    this->perimeterPoints = new Point2D[this->Rect2D::get_num_of_points()];
    calc();
}
Rect2D::~Rect2D(){
    
    delete [] this-> perimeterPoints;
    
}

void Rect2D::calc(){
    
    int idx =0;
    int wstart = center.x - width/2;
    int wend = center.x + width/2;
    int hstart = center.y - height/2;
    int hend = center.y + height/2;
    
    //왼쪽 끝 세로 점 계산
    if(width%2 == 0){
        for (int i = hstart; i<=hend; i++){
            perimeterPoints[idx++] = {wstart,i};
        }
    }
    //중간 점 계산
    if(height%2==0){
        
        if(width%2 == 0){
            wstart += 1;
            wend -= 1;
        }
        for (int i = wstart; i<= wend; i++){
            perimeterPoints[idx++] = {i,hstart};
            perimeterPoints[idx++] = {i,hend};
        }
        wend += 1;
    }
    if(width%2 == 0){
        for (int i = hstart; i<=hend; i++){
            perimeterPoints[idx++] = {wend,i};
        }
    }
    
        
}
const Point2D* Rect2D::get_perimeter_points() const {
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
int Rect2D::get_num_of_points() const{
    
    if((width%2)==0 && (height%2)==0 )
        return 2*(this -> width + this -> height);
    else if((width%2) != 0 && (height%2)!=0)
        return 0;
    else if(width%2 == 0)
        return 2*height;
    else
        return 2*width;
}
