//
//  MyList.h
//  Week10Train
//
//  Created by 유진원 on 11/20/24.
//

#ifndef MyList_h
#define MyList_h

template<typename T>
class MyList{

public:
    class ListNode { // inner class

    public: // ListNode는 public 멤버 변수 허용
        T data;
        ListNode * next;
        ListNode() : data(0), next(nullptr){};
        ListNode(T);
    };
private:
    ListNode* first;
    int size;
    
public:
    MyList();
    MyList(MyList &);
    ~MyList();
    int get_size() const;
    void append(T);
    int remove_all(T);
    T at(int);
    void insert_at(int,T);
    
};
template<typename T>
MyList<T>::ListNode::ListNode(T data) : data(data), next(nullptr) {}

template<typename T>
MyList<T>::MyList():first(nullptr){}

template<typename T>
MyList<T>::MyList(MyList & other){
    
}

template<typename T>
MyList<T>::~MyList(){
    while (first != nullptr) {
        ListNode* tmp = first->next;
        delete first;
        first = tmp;
    }
}

template<typename T>
int MyList<T>::get_size() const{
    return size;
}

template<typename T>
void MyList<T>::append(T data){
    ListNode *tmp = new ListNode(data);
    if(first == nullptr){
        first = tmp;
        size += 1;
    }
    else{
        ListNode *tmp2 = first;
        while(1){
            if (tmp2->next == nullptr)
                break;
            tmp2 = tmp2 -> next;
        }
        tmp2 -> next = tmp;
        size += 1;
    }
}
template<typename T>
int MyList<T>::remove_all(T data){
    int count = 0;
    while(first != nullptr && first->data == data){
        ListNode * tmp = first;
        first = first -> next;
        delete tmp;
        count+=1;
    }
    ListNode *curr = first;
    while (curr != nullptr && curr -> next != nullptr){
        if (curr->next->data == data) {
            ListNode* tmp = curr->next;
            curr->next = curr->next->next;
            delete tmp;
            count+=1;
        }
        else
            curr = curr->next;
    }
    return count;
}
template<typename T>
T MyList<T>::at(int idx){
    ListNode *tmp = first;
    for (int i = 0; i <idx; i++){
        tmp = tmp -> next;
    }
    return tmp -> data;
}
template<typename T>
void MyList<T>::insert_at(int idx ,T data){
    ListNode* tmp = new ListNode(data);
    if (idx == 0) {
        tmp->next = first;
        first = tmp;
        return;
    }
    ListNode* tmp2 = first;
    for (int i = 0; i < idx - 1; i++) {
        tmp2 = tmp2->next;
    }
    tmp->next = tmp2->next;
    tmp2->next = tmp;
}
#endif /* MyList_h */
