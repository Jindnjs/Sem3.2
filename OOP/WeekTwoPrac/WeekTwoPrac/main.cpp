//
//  main.cpp
//  WeekTwoPrac
//
//  Created by 유진원 on 9/24/24.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    
    int S[2][3] = {1,2,3,4,5,6};
    
    std::cout << *(&S[0][0]+3*1+2) <<std::endl;
    std::cout << (*(S+1))[2] <<std::endl;
    
}
