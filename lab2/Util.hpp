//
//  Util.hpp
//  lab2
//
//  Created by Ilyakulebyakin on 11/13/15.
//  Copyright © 2015 KulebyakinSnitsar. All rights reserved.
//

#import <iostream>

void printFormattedParents(int num);

template <typename T>
T* reallocate(T* what, int oldSize, int newSize) {
    T* tmp = new T[newSize];
    std::copy(what, what + oldSize, tmp);
    delete [] what;
    return tmp;
}
