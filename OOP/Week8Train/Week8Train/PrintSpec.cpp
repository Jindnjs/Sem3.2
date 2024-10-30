//
//  PrintSpec.cpp
//  Week8Train
//
//  Created by 유진원 on 10/30/24.
//

#include <stdio.h>

#include <iostream>
#include "Shape2D.h"


void PrintSpec(Shape2D *s){
    std::cout<< "===================" <<std::endl;
    std::cout<< s-> get_name() << std::endl;
    std::cout<< "center is : (" << s->get_center().x <<
    ", "<<s->get_center().y << ")" << std::endl;
    std::cout<< "Area is : " << s->get_area()<<std::endl;
    std::cout<< "PerimiterPoints" <<std::endl;
    for (int i = 0; i<s->; i++){
            std::cout << std::right << std::setw(maxLen+1) << arr[i];
            if ((i + 1) % 10 == 0) {
                std::cout << std::endl;
            }
    }
}
