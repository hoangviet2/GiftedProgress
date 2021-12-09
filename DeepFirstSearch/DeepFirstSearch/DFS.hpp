//
//  DFS.hpp
//  DeepFirstSearch
//
//  Created by Hoang Viet on 09/10/2021.
//

#ifndef DFS_hpp
#define DFS_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
class Graph{
private:
    vector<vector<ll>> adjacency;
    vector<int> rowNbr = { -1, -1, -1, 0, 0, 1, 1, 1 };
    vector<int> colNbr = { -1, 0, 1, -1, 1, -1, 0, 1 };
public:
    Graph(ll sizes){
        adjacency = vector<vector<ll>>(sizes,vector<ll>(sizes));
    }
    Graph(vector<vector<ll>> adjacencys){
        adjacency = adjacencys;
    }
    
    // A utility function to add an edge in an
    // undirected graph.
    void addEdge(vector<vector<ll>>,ll,ll);
      
    // A utility function to print the adjacency list
    // representation of graph
    void printGraph(vector<vector<ll>>,ll);
    
    // Check is the element inside the Graph
    bool isSafe(ll,ll);
    
    // Deep First seach
    // Following the condition on: https://www.geeksforgeeks.org/find-number-of-islands/
    void DFS(ll,ll);
    
    ll countIsland();
};
#endif /* DFS_hpp */
