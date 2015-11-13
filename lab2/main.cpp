//
//  main.cpp
//  lab2
//
//  Created by Ilyakulebyakin on 11/13/15.
//  Copyright © 2015 KulebyakinSnitsar. All rights reserved.
//

#import <iostream>
#import "Tree.hpp"

int main(int argc, const char * argv[]) {
    Tree *tree = new Tree();
    tree->represent();
    tree->inOrderTraversal();
    tree->depthFirstTraversalNonRecursive();
    tree->depthFirstTraversal();
    tree->breadthFirstTraversal();
    delete tree;
    
    return 0;
}
