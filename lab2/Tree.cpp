//
//  Tree.cpp
//  lab2
//
//  Created by Ilyakulebyakin on 11/13/15.
//  Copyright © 2015 KulebyakinSnitsar. All rights reserved.
//

#import "Tree.hpp"
#import "Util.hpp"
#import "Stack.hpp"
#import "Queue.hpp"

const int kScreenWidth = 80;
const char kStartTag = 'a';
const char kMaxTag = 'z';
const int kMaxDepth = 6;
const char kFillSymbol = ' ';

struct Link {
    char tag;
    Link* left;
    Link* right;
    
    Link(char tag, Link* left, Link* right): tag(tag), left(left), right(right) { };
    Link(char tag): Link(tag, nullptr, nullptr) { };
    Link(Link* left, Link* right): Link('\0', left, right) { };
    
    ~Link() {
        delete left;
        delete right;
    }
    
    void setScreenData(char** screenData, int depth, int offset) {
        if (depth > 0 && offset > 0 && offset <= kScreenWidth) {
            screenData[depth - 1][offset - 1] = tag;
        }
        
        if (left) {
            left->setScreenData(screenData, depth + 1, offset - ((kScreenWidth / 2) >> depth));
        }
        if (right) {
            right->setScreenData(screenData, depth + 1, offset + ((kScreenWidth / 2) >> depth));
        }
    }
    
    void traverseInOrder(int depth) {
        if (left) {
            left->traverseInOrder(depth + 1);
        }
        
        std::cout << tag << " (";
        printFormattedParents(depth);
        std::cout << "), ";
        
        if (right) {
            right->traverseInOrder(depth + 1);
        }
    }
    
    void addToStackDepthFirst(Stack<Link>* stack) {
        if (right) {
            right->addToStackDepthFirst(stack);
        }
        if (left) {
            left->addToStackDepthFirst(stack);
        }
        stack->push(this);
    }
    
    void addToQueueBreadthFirst(Queue<Link>* queue) {
        if (left) {
            queue->addToQueue(left);
        }
        if (right) {
            queue->addToQueue(right);
        }
        if (left) {
            left->addToQueueBreadthFirst(queue);
        }
        if (right) {
            right->addToQueueBreadthFirst(queue);
        }
    }
    
    void traverseDepthFirst() {
        std::cout << tag << ", ";
        
        if (left) {
            left->traverseDepthFirst();
        }
        
        if (right) {
            right->traverseDepthFirst();
        }
    }
    
};

Tree::Tree() {
    _currentTag = kStartTag;
    _root = makeSubTree(1);
    
    _screenData = new char*[kMaxDepth];
    for (int i = 0; i < kMaxDepth; ++i) {
        _screenData[i] = new char[kScreenWidth + 1];
        memset(_screenData[i], kFillSymbol, kScreenWidth + 1);
    }
}

Tree::~Tree() {
    delete _root;
    for (int i = 0; i < kMaxDepth; ++i) {
        delete [] _screenData[i];
    }
    delete [] _screenData;
}

Link* Tree::makeSubTree(int depth) {
    if ((depth < arc4random() % 6 + 1) && (_currentTag <= kMaxTag)) {
        Link* subTree = new Link(makeSubTree(depth + 1), makeSubTree(depth + 1));
        subTree->tag = _currentTag++;
        return subTree;
    }
    return nullptr;
}

void Tree::represent() {
    if (_root) {
        _root->setScreenData(_screenData, 1, kScreenWidth / 2);
    }
    for (int i = 0; i < kMaxDepth; ++i) {
        _screenData[i][kScreenWidth] = '\0';
        std::cout << _screenData[i] << std::endl;
    }
}

void Tree::inOrderTraversal() {
    std:: cout << "Внутренний обход(задание): {";
    if (_root) {
        _root->traverseInOrder(0);
    }
    std::cout << "\b\b}" << std::endl;
}

void Tree::breadthFirstTraversal() {
    std::cout << "Обход в ширину: {";
    Queue<Link>* queue = new Queue<Link>();
    if (_root) {
        queue->addToQueue(_root);
        _root->addToQueueBreadthFirst(queue);
    }
    
    while (!queue->isEmpty()) {
        std::cout << queue->getFromQueue()->tag << ", ";
    }
    delete queue;
    
    std::cout << "\b\b}" << std::endl;
}

void Tree::depthFirstTraversalNonRecursive() {
    Stack<Link>* stack = new Stack<Link>();
    
    if (_root) {
        _root->addToStackDepthFirst(stack);
    }
    
    std::cout << "Обход в глубину без рекурсии: {";
    while (!stack->isEmpty()) {
        std::cout << stack->pop()->tag << ", ";
    }
    delete stack;
    std::cout << "\b\b}" << std::endl;
    
}

void Tree::depthFirstTraversal() {
    std::cout << "Обход в глубину: {";

    if (_root) {
        _root->traverseDepthFirst();
    }
    
    std::cout << "\b\b}" << std::endl;
    
}

