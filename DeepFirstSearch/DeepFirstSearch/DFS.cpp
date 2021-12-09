//
//  DFS.cpp
//  DeepFirstSearch
//
//  Created by Hoang Viet on 09/10/2021.
//

#include "DFS.hpp"
void Graph::addEdge(vector<vector<ll>> adj, ll u, ll v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void Graph::printGraph(vector<vector<ll>> adj, ll V)
{
    for (int v = 0; v < V; ++v)
    {
        cout << "\n Adjacency list of vertex "
             << v << "\n head ";
        for (auto x : adj[v])
           cout << "-> " << x;
        printf("\n");
    }
}
bool Graph::isSafe(ll col, ll row){
    return (row>=0) && (row<adjacency.size()) && (col>=0) && (col<adjacency.size()) && (adjacency[row][col] != 0);
}
void Graph::DFS(ll col, ll row){
    if(isSafe(col,row)){
        adjacency[row][col] = 0;
        for(int i=0;i<8;++i){
            DFS(col+colNbr[i], row+rowNbr[i]);
        }
    }
    return;
}

ll Graph::countIsland(){
    ll ans = 0;
    for(ll i = 0;i<adjacency.size();++i){
        for(ll j=0;j<adjacency[0].size();++j){
            if(adjacency[i][j] == 1){
                adjacency[i][j] = 0;
                ans++;
                for(int z=0;z<8;++z){
                    DFS(j+colNbr[z], i+rowNbr[z]);
                }
            }
        }
    }
    return ans;
}
