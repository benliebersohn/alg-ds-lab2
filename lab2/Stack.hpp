//
//  Stack.hpp
//  lab2
//
//  Created by Ilyakulebyakin on 11/13/15.
//  Copyright © 2015 KulebyakinSnitsar. All rights reserved.
//

template <typename T>
class Stack {
    int _capacity;
    int _size;
    T** _array;
    
public:
    Stack() {
        _capacity = 2;
        _size = 0;
        _array = new T*[_capacity];
    }
    
    void push(T* element) {
        if (_capacity == _size) {
            _array = reallocate(_array, _size, _capacity *= 2);
        }
        _array[_size++] = element;
    }
    
    T* pop() {
        return _array[--_size];
    }
    
    bool isEmpty() {
        return !_size;
    }
    
    ~Stack() {
        delete [] _array;
    }
};