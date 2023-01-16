//
//  Solution.hpp
//  BFS
//
//  Created by Hoang Viet on 11/11/2021.
//

#ifndef Solution_hpp
#define Solution_hpp
#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;
struct zeroPathOperationsInput{
    map<int,int> nodeFre;
    zeroPathOperationsInput(int numberOfNode){
        int from,to;
        for(int i=0;i<numberOfNode-1;++i){
            cin>>from>>to;
            nodeFre[from-1]++;
            nodeFre[to-1]++;
        }
    }
};
struct minimumCostInput{
    vector<pair<int,int>> graph[50003];
    vector<int> distances[50003];
    minimumCostInput(int destination){
        for(int i=0;i<destination;++i){
            int node;
            cin>>node;
            graph[i+1].push_back(make_pair(node, 0));
            if(i<node-1){
                graph[i+1].push_back(make_pair(node+1, <#_T2 &&__t2#>))
            }
        }
    }
};
class Solution{
public:
    Solution(){cout<<"Begin";};
    void zeroPathOperations();
    void minimumCost();
    void permutation();
    void theFlightPlan();
    void travelDiaries();
    void shortestDistanceProblem();
    void escapeFromGrid();
    void roboticPaths();
    void levelNodes();
    void primeCells();
    void printingPatterns();
    ~Solution(){cout<<"End";};
};
#endif /* Solution_hpp */
