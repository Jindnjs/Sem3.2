//
//  main.cpp
//  OopWeek5Train
//
//  Created by 유진원 on 10/2/24.
//

#include <iostream>
#include <string>
#include <iomanip>

bool check_pp(unsigned int);
void append_pp(unsigned int *, int);

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int n;
    std::cin >> n;
    
    if (std::cin.fail() || n <= 0)
        return 0;
        
    if (std::cin.peek() != '\n')
        return 0;
    
    unsigned int *arr = new unsigned int[n];
    
    append_pp(arr, n);
    
    int maxLen = (int)std::to_string(arr[n-1]).length();
    
    for (int i = 0; i<n; i++){
        std::cout << std::right << std::setw(maxLen+1) << arr[i];
        if ((i + 1) % 10 == 0) {
            std::cout << std::endl;
        }
    }
    
    delete [] arr;
    
    std::cout << std::endl;
    return 0;
}

bool check_pp(unsigned int a){
    if (a <= 1)
        return false;
    if (a <= 3)
        return true;
    if (a % 2 == 0)
        return false;
    for (int i = 2; i <= sqrt(a); i++) {
        if (a % i == 0)
            return false;
    }
    
    std::string tmp = std::to_string(a);
    std::string::size_type size = tmp.size();

    for(std::string::size_type i = 0; i < size / 2; i++) {
        if(tmp[i] != tmp[size - 1 - i])
            return false;
    }
    
    return true;
    
}

void append_pp(unsigned int *arr, int n){
    
    int count = 0;
    unsigned int i = 1;
    
    while(true){
        
        if (count == n)
            break;
        
        if (check_pp(i)){
            arr[count] = i;
            count ++;
        }
        
        i++;
    }
}
