//
//  MyQueue.h
//  Week11Train
//
//  Created by 유진원 on 11/27/24.
//

#ifndef MyQueue_h
#define MyQueue_h

#include "ContainerAdapter.h"
#include <deque>

template <typename T>
class MyQueue : public ContainerAdapter<T>{
public:
    void push(const T& value);
    T& front();
    void pop();
};

template <typename T>
void MyQueue<T>::push(const T& value){
    this->container.push_back(value);
}

template <typename T>
T& MyQueue<T>::front(){
    return this->container.front();
}

template <typename T>
void MyQueue<T>::pop(){
    this -> container.pop_front();
}

#endif /* MyQueue_h */
