//
//  MyStack.h
//  Week11Train
//
//  Created by 유진원 on 11/27/24.
//

#ifndef MyStack_h
#define MyStack_h

#include "ContainerAdapter.h"
#include <deque>
template <typename T>
class MyStack : public ContainerAdapter<T>{
public:
    void push(const T& value);
    T& front();
    void pop();
};

template <typename T>
void MyStack<T>::push(const T& value){
    this->container.push_back(value);
}

template <typename T>
T& MyStack<T>::front(){
    return this->container.back();
}

template <typename T>
void MyStack<T>::pop(){
    this -> container.pop_back();
}
#endif /* MyStack_h */
