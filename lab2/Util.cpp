//
//  Util.cpp
//  lab2
//
//  Created by Ilyakulebyakin on 11/13/15.
//  Copyright © 2015 KulebyakinSnitsar. All rights reserved.
//

#import "Util.hpp"

void printFormattedParents(int num) {
    switch (num) {
        case 0:
            std::cout << "корень дерева, предков нет";
            break;
        case 1:
            std::cout << num << " предок";
            break;
        case 2:
        case 3:
        case 4:
            std::cout << num << " предка";
            break;
        default:
            std::cout << num << " предков";
            break;
    }
}
