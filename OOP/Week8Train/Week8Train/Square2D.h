//
//  Square2D.hpp
//  Week8Train
//
//  Created by 유진원 on 10/30/24.
//

#ifndef Square2D_hpp
#define Square2D_hpp

#include "Point2D.h"
#include "Rect2D.h"

class Square2D : public Rect2D{
public:
    Square2D(Point2D,int);
    ~Square2D();
    const std::string get_name() const;
};

#endif /* Square2D_hpp */
