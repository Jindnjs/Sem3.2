//
//  main.cpp
//  Week12Train
//
//  Created by 유진원 on 12/18/24.
//

#include <iostream>
#include "AbsenteeListImpl.h"
int main(int argc, const char * argv[]) {
    // Instantiate the concrete class
    AbsenteeListImpl absentee_list;

    // Test data
    std::vector<std::string> mid = {"Frank","Alice", "Bob", "Charlie", "David"};
    std::vector<std::string> finals = {"Charlie", "David", "Eve", "Frank"};


    // Get the output
    std::string output = absentee_list.find_absentee(mid, finals);
    std::cout << "F Grade Students:\n" << output;

    // Expected output:
    // 2
    // Charlie
    // David
    return 0;
}
