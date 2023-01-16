//
//  ZeroPathOperations.cpp
//  BFS
//
//  Created by Hoang Viet on 04/11/2021.
//
// đề bài: https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/practice-problems/algorithm/zero-path-a7d370fd/

#include <iostream>
#include <map>
using namespace std;
void ZeroPathOperations(){
    int testCase;
    cin>>testCase;
    while (testCase>0) {
        --testCase;
        int ans = 0;
        int fromNode,toNode,nodesNumber,node;
        map<int,int> nodeFrequency;
        cin>>nodesNumber;
        for(int i=0;i<nodesNumber-1;++i){
            cin>>fromNode>>toNode;
            nodeFrequency[fromNode-1]++;
            nodeFrequency[toNode-1]++;
        }
        for(int i=0;i<nodesNumber;++i){
            cin>>node;
            if(node!=0&&nodeFrequency[i]>1){
                ++ans;
            }
        }
        cout<<ans<<'\n';
    }
}
//int main(){
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
//    ZeroPathOperations();
//    return 0;
//}
