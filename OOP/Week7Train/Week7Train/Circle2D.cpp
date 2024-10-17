//
//  Circle2D.cpp
//  Week7Train
//
//  Created by 유진원 on 10/16/24.
//

#include "Circle2D.h"

#include <cmath>
#include <string>
#include <iostream>

//내부함수
int Circle2D::calcPoints(){
    int r = this->radius;
    if(r<= 0)
        return 0;
    return (2*r - 1)*2 + 2;
}

void Circle2D::setPermeterPoints(){
    
    if(calcPoints() == 0){
        delete [] perimeterPoints;
        perimeterPoints = nullptr;
        return;
    }
    int centerX = this->center.x;
    int centerY = this->center.y;
    int idx = 0;
    for(int x = centerX-this->radius; x <= centerX; x++){
        
        //x축에서 2개추가
        if(x == centerX - this->radius){
            perimeterPoints[idx++] = {x,centerY};
            perimeterPoints[idx++] = {centerX + radius,centerY};
        }
        //y축에서 2개 추가
        else if(x == centerX){
            perimeterPoints[idx++] = {centerX,centerY+radius};
            perimeterPoints[idx++] = {centerX,centerY-radius};
        }
        //4개 추가
        else{
            int x2 = (x - centerX)*(x-centerX);
            int y2 = radius*radius - x2;
            int y = static_cast<int>(round(sqrt(y2)));
            
            //y중심좌표만큼 더하고뺴깅
            perimeterPoints[idx++] = {x,y+centerY};
            perimeterPoints[idx++] = {x,-y + centerY};
            
            x2 = (centerX - x)*(centerX - x);
            y2 = radius*radius-x2;
            y = static_cast<int>(round(sqrt(y2)));
            
            perimeterPoints[idx++] = {2*centerX - x,y+centerY};
            perimeterPoints[idx++] = {2*centerX - x,-y+centerY};
        }
    }
}

void Circle2D::pointPrint(){
    
    if (calcPoints()==0){
        std::cout <<"출력할 변수가 없습니다"<<std::endl;
        return;
    }
    
    for(int i = 0 ; i < calcPoints(); i++){
        
        std::cout << "(" << this->perimeterPoints[i].x << "," << this-> perimeterPoints[i].y << ")" << std::endl;
    }
    std::cout << "=========" << std::endl;
}

//Constructor
Circle2D::Circle2D(Point2D center, int radius){
    
    //예외처리
    
    this->center = center;
    this->radius = radius;
    
    if(radius <= 0){
        this->perimeterPoints = nullptr;
        return;
    }
    //배열 동적할당
    this->perimeterPoints = new Point2D [calcPoints()];
    
    //점 계산
    setPermeterPoints();
}
Circle2D::Circle2D(const Circle2D & circle){
    
    //멤버 초기화
    this -> center = circle.getCenter();
    this -> radius = circle.getRadius();
    
    if(radius <= 0){
        this->perimeterPoints = nullptr;
        return;
    }
    this -> perimeterPoints = new Point2D [calcPoints()];
    for (int i=0; i<calcPoints();i++)
        this->perimeterPoints[i] = circle.getPerimeterPoints()[i];

}
Circle2D::~Circle2D(){
    
    delete [] this -> perimeterPoints;
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
    //예외처리??
    
    this->center = center;
    
    //배열 재할당
    delete [] perimeterPoints;
    perimeterPoints = new Point2D [calcPoints()];
    //점 계산
    setPermeterPoints();
    
}
void Circle2D::setRadius(int radius){
    //예외처리??
    
    
    this->radius = radius;
    
    if(radius <= 0){
        delete this->perimeterPoints;
        this->perimeterPoints = nullptr;
        return;
    }
    //배열 재할당
    delete [] perimeterPoints;
    perimeterPoints = new Point2D [calcPoints()];
    //점 계산
    setPermeterPoints();
}




