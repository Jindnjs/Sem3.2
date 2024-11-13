//
//  Vector2D.h
//  Week9Train
//
//  Created by 유진원 on 11/13/24.
//

#ifndef Vector2D_h
#define Vector2D_h
#include <cmath>
class Vector2D{
private:
    int x, y;
public:
    int get_x() const;
    int get_y() const;
    void set_x(int);
    void set_y(int);
    //void normalize();
    double magnitude() const;
    int dot_product(const Vector2D&) const;
public:
    Vector2D& operator +=(const Vector2D&);
    Vector2D& operator -=(const Vector2D&);
    friend Vector2D operator+ (const Vector2D&,const Vector2D&);
    friend Vector2D operator- (const Vector2D&,const Vector2D&);
    friend int operator* (const Vector2D&,const Vector2D&);
};

#endif /* Vector2D_h */
