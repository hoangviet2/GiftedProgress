//
//  GraphStandard.hpp
//  DeepFirstSearch
//
//  Created by Hoang Viet on 15/10/2021.
//

#ifndef GraphStandard_hpp
#define GraphStandard_hpp

#include <stdio.h>
#include <iostream>
#include <list>
using namespace std;
class GraphStd{
private:
    int size;
    bool **tc;
    list<int> *adjacencys;
    void DSUntil(int,int);
    bool isCyclicUntil(int v, bool visited[],int parent);
public:
    GraphStd(int V);//Constructor
    //add edge
    void addEdge(int v,int w){adjacencys[v].push_back(w);};
    void addEdgeCircle();
    //Print
    void transitiveClosure();
    // check if it a cirle
    bool isCyclic();
    // longest cable
    
};
#endif /* GraphStandard_hpp */
