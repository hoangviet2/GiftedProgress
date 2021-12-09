//
//  minimumCost.cpp
//  BFS
//
//  Created by Hoang Viet on 07/11/2021.
//

#include <vector>
#include <utility>
#include <queue>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

vector<pair<int,int>>graph[50003];
vector<int>distances(50003);

int bfs(int s,int n){
    deque<int>queue;
    queue.push_back(s);
    distances[s]=0;
    while(!queue.empty()){
        int front=queue.front();
        queue.pop_front();
        for(int i=0;i<graph[front].size();i++){
            if(distances[graph[front][i].first]>distances[front]+graph[front][i].second){
                distances[graph[front][i].first]=distances[front]+graph[front][i].second;
                if(graph[front][i].second==0){
                    queue.push_front(graph[front][i].first);
                }else{
                    queue.push_back(graph[front][i].first);
                }

            }

        }

    }
    return distances[n];
}

//int main(){
//
//    int testCases,n,j;
//
//    cin>>testCases;
//
//    while(testCases--){
//
//        cin>>n;
//
//        for(int i=0;i<n;i++){
//
//            cin>>j;
//
//            graph[i+1].push_back(make_pair(j,0));
//
//            if(i<n-1){
//
//                graph[i+1].push_back(make_pair(j+1,1));
//                
//            }
//
//            if(i>0){
//
//                graph[i+1].push_back(make_pair(j-1,1));
//
//            }
//            distances[i+1]=INT_MAX;
//        }
//
//        cout<<bfs(1,n)<<"\n";
//        for(int i=0;i<=n;i++){
//
//            graph[i].clear();
//
//        }
//
// 
//
//    }
//    return 0;
//}

