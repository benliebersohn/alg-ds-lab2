//
//  Tree.hpp
//  lab2
//
//  Created by Ilyakulebyakin on 11/13/15.
//  Copyright © 2015 KulebyakinSnitsar. All rights reserved.
//

#import <iostream>

struct Link;

class Tree {
    Link* _root;
    char _currentTag;
    char** _screenData;
    Link* makeSubTree(int depth);
public:
    Tree();
    ~Tree();
    void represent();
    void inOrderTraversal();
    void depthFirstTraversalNonRecursive();
    void depthFirstTraversal();
    void breadthFirstTraversal();
};