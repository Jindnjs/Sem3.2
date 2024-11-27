//
//  ContainerAdapter.h
//  Week11Train
//
//  Created by 유진원 on 11/27/24.
//

#ifndef ContainerAdapter_h
#define ContainerAdapter_h

template <typename T>

class ContainerAdapter {
    
protected:
    
    std::deque<T> container;
    
public:
    
    bool empty() const {
        return container.empty();
    }
    
    size_t size() const {
        return container.size();
    }
    
    virtual void push(const T& value) = 0;
    virtual T& front() = 0;
    virtual void pop() = 0;
    
    ContainerAdapter() = default;
    ContainerAdapter(const ContainerAdapter&) = default;
    ContainerAdapter& operator=(const ContainerAdapter&) = default;
    virtual ~ContainerAdapter() = default;
    
};

#endif /* ContainerAdapter_h */
