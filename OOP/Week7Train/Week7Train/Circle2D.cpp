//
//  Circle2D.cpp
//  Week7Train
//
//  Created by 유진원 on 10/16/24.
//

#include "Circle2D.hpp"

#include <cmath>
#include <string>


//Constructor
Circle2D::Circle2D(Point2D center, int radius){
    
    //예외처리
    
    this->center = center;
    this->radius = radius;
    
    //배열 동적할당
    //점 갯수 계산
    //지정
}
Circle2D::Circle2D(const Circle2D & circle){
    
    //멤버 초기화
    
    //배열 동적할당
    //memcpy
    //
}
Circle2D::~Circle2D(){
    
    //메모리 해제
}

//getter
Point2D Circle2D::getCenter() const{
    return this->center;
}
int Circle2D::getRadius() const{
    return this->radius;
}
const Point2D * Circle2D::getPerimeterPoints() const{
    return this->perimeterPoints;
}

//setter
void Circle2D::setCenter(Point2D center){
    //예외처리
    this->center = center;
    
    //배열 동적할당
    //점 갯수 계산
    //지정
}
void Circle2D::setRadius(int radius){
    //예외처리
    this->radius = radius;
    
    //배열 동적할당
    //점 갯수 계산
    //지정
}




