//
//  Solution.cpp
//  BFS
//
//  Created by Hoang Viet on 11/11/2021.
//

#include "Solution.hpp"
void Solution::zeroPathOperations(){
    int testCase;
    cin>>testCase;
    while(testCase>0){
        --testCase;
        int ans = 0;
        int numberOfNode;
        cin>>numberOfNode;
        zeroPathOperationsInput target(numberOfNode);
        map<int,int> NodeFreq = target.nodeFre;
        for(int i=0;i<numberOfNode;++i){
            int node;
            cin>>node;
            if(node!=0 && NodeFreq[i]>1){
                ++ans;
            }
        }
        cout<<ans<<"\n";
    }
}
void Solution::minimumCost(){
    int testCase,destination,node;
    cin>>testCase;
    while (testCase>0) {
        --testCase;
        cin>>destination;
        for(int i=0;i<destination;++i){
            cin>>node;
        }
    }
}
