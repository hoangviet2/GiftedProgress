//
//  Node.cpp
//  DeepFirstSearch
//
//  Created by Hoang Viet on 16/10/2021.
//

#include <iostream>
#include "Node.hpp"
using namespace std;
class Node{
private:
    int previous;
    int next;
    int val;
public:
    Node(){cout<<"Node created"<<"\n";};
    
    ~Node(){cout<<"Destroyed"<<"\n";};
};
