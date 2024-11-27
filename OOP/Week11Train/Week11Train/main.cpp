//
//  main.cpp
//  Week11Train
//
//  Created by 유진원 on 11/27/24.
//

#include <iostream>
#include "MyStack.h"
#include "MyQueue.h"
#include <deque>

template <typename T>
T queuestack_push_pop(ContainerAdapter<T>** queuestack, int len, T& value){
    
    for(int i=0;i<len;i++){
        queuestack[i] -> push(value);
        value =queuestack[i] -> front();
        queuestack[i] -> pop();
    }
    return value;
}

template <typename T>
void queuestack_create(ContainerAdapter<T>** queuestack, int* q_or_s, int len){
    
    for(int i=0;i<len;i++){
        if (q_or_s[i] == 0)
            queuestack[i] = new MyQueue<T>;
        else
            queuestack[i] = new MyStack<T>;
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int N,M;
    int q_or_s [100000];
    std::cin >> N;
    MyStack<int> st;
    
    ContainerAdapter<int> ** queuestack = new ContainerAdapter<int> * [N];
    for (int i=0;i<N;i++){
        std::cin >> q_or_s[i];
    }
    queuestack_create(queuestack, q_or_s, N);
    
    int k;
    for (int i=0;i<N;i++){
        std::cin >> k;
        queuestack[i] -> push(k);
    }
    
    std::cin >> M;
    
    for (int i=0;i<M;i++){
        std::cin >> k;
        std::cout << queuestack_push_pop(queuestack,N,k) << " ";
    }
    std::cout << std::endl;
    
    for (int i = 0; i < N; i++) {
        delete queuestack[i];
    }
    delete[] queuestack;
    
    return 0;
}

