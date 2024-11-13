//
//  Vector2D.cpp
//  Week9Train
//
//  Created by 유진원 on 11/13/24.
//

#include "Vector2D.h"

int Vector2D::get_x() const{
    return x;
}
int Vector2D::get_y() const{
    return y;
}
void Vector2D::set_x(int x){
    this->x = x;
}
void Vector2D::set_y(int y){
    this->y = y;
}
//    void normalize();
double Vector2D::magnitude() const{
    return sqrt(pow(x,2) + pow(y,2));
}
int Vector2D::dot_product(const Vector2D& other) const{
    return ((x*other.x)+(y*other.y));
}
Vector2D& Vector2D::operator +=(const Vector2D& right){
    x += right.x;
    y += right.y;
    return *this;
}
Vector2D& Vector2D::operator -=(const Vector2D& right){
    x -= right.x;
    y -= right.y;
    return *this;
}
Vector2D operator+ (const Vector2D& left,const Vector2D& right){
    Vector2D tmp;
    tmp.x = left.x + right.x;
    tmp.y = left.y + right.y;
    return tmp;
}
Vector2D operator- (const Vector2D& left,const Vector2D& right){
    Vector2D tmp;
    tmp.x = left.x - right.x;
    tmp.y = left.y - right.y;
    return tmp;
}
int operator* (const Vector2D& left,const Vector2D& right){
    return left.dot_product(right);
}
