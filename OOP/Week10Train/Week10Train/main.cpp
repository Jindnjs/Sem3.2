//
//  main.cpp
//  Week10Train
//
//  Created by 유진원 on 11/20/24.
//

#include <iostream>
#include <string>
#include "MyList.h"
int main(int argc, const char * argv[]) {
    // insert code here...
    MyList <std::string> sList;
    sList.append("hello");
    sList.print();
    sList.append("my");
    sList.print();
    sList.append("name");
    sList.print();
    sList.append("is");
    sList.print();
    
    sList.insert_at(5, "0");
    sList.print();
    
    MyList<int> iList;
    iList.append(1);
    iList.append(2);
    iList.append(1);
    iList.append(2);
    iList.append(3);
    iList.print();
    std::cout << iList.remove_all(3) << std::endl;
    iList.print();
    std::cout <<iList.at(0);
    std::cout <<iList.at(1);
    std::cout << iList.at(2);
    std::cout << iList.at(3);

    return 0;
}
