//
//  Circle2D.hpp
//  Week8Train
//
//  Created by 유진원 on 10/30/24.
//

#ifndef Circle2D_hpp
#define Circle2D_hpp

#include "Ellipse2D.h"
#include "Point2D.h"
class Circle2D:public Ellipse2D{
public:
    Circle2D(Point2D,int);
    ~Circle2D();
    const std::string get_name() const;
};
#endif /* Circle2D_hpp */
