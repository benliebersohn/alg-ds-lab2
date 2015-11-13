//
//  Queue.hpp
//  lab2
//
//  Created by Ilyakulebyakin on 11/13/15.
//  Copyright © 2015 KulebyakinSnitsar. All rights reserved.
//

template <typename T>
struct Node {
    T* element;
    Node<T>* succ;
    
    Node(T* element, Node<T>* succ): element(element), succ(succ) {};
    Node(T* element): Node(element, nullptr) {};
};

template <typename T>
class Queue {
    Node<T>* listStart;
    Node<T>* listEnd;
    
public:
    Queue() {
        listStart = nullptr;
        listEnd = nullptr;
    }
    
    void addToQueue(T* element) {
        if (!listStart) {
            listStart = listEnd = new Node<T>(element);
        } else {
            listEnd->succ = new Node<T>(element);
            listEnd = listEnd->succ;
        }
    }
    
    T* getFromQueue() {
        if (listStart) {
            Node<T>* tmp = listStart;
            listStart = listStart->succ;
            T* element = tmp->element;
            delete tmp;
            return element;
        }
        return nullptr;
    }
    
    bool isEmpty() {
        return !listStart;
    }
};