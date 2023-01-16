//
//  main.cpp
//  BFS
//
//  Created by Hoang Viet on 03/11/2021.
//

#include <iostream>
#include <queue>
#include <vector>
using namespace std;
vector<bool> visited;
vector<vector<int>> graphstd;
int ans = 0;
void edge(int a, int b)
{
    graphstd[a].push_back(b);
    // for undirected graphstd add this line
    // g[b].pb(a);
}

void BFS(int node){
    queue<int> waiting_room;
    waiting_room.push(node);
    visited[node] = false;
    while(!waiting_room.empty()){
        int checkingNode = waiting_room.front();
        waiting_room.pop();
        cout<<checkingNode<<" ";
        ans += graphstd[checkingNode].size();
        for(auto it = graphstd[checkingNode].begin() ; it<graphstd[checkingNode].end();++it){
            if(!visited[*it]){
                waiting_room.push(*it);
                visited[*it] = true;
            }
        }
    }
}
//int main()
//{
//    int n, e;
//    cin >> n >> e;
//
//    visited.assign(n, false);
//    graphstd.assign(n, vector<int>());
//
//    int a, b;
//    for (int i = 0; i < e; i++) {
//        cin >> a >> b;
//        edge(a-1, b-1);
//    }
//
//    for (int i = 0; i < n; i++) {
//        if (!visited[i])
//            BFS(i);
//    }
//    cout<<'\n';
//    cout<<ans;
//    return 0;
//}
