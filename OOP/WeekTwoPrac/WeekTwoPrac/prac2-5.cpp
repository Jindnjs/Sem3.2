//
//  prac2-5.cpp
//  WeekTwoPrac
//
//  Created by 유진원 on 9/25/24.
//

#include <iostream>

int main(){
 
    int balance = 0;
    int transaction;
    
    std::cout << "첫 번째 거래 금액 입력 : ";
    std::cin >> transaction;
    balance += transaction;
    
    std::cout << "두 번째 거래 금액 입력 : ";
    std::cin >> transaction;
    balance += transaction;
    
    std::cout << "세 번째 거래 금액 입력 : ";
    std::cin >> transaction;
    balance += transaction;
    
    std::cout << "최종 거래 금액 : " << balance << "달러입니다" << std::endl;
    
    return 0;
}
