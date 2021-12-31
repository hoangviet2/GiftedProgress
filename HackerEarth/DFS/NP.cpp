//Problem link: https://www.hackerearth.com/practice/algorithms/graphs/graph-representation/practice-problems/algorithm/so-np-c559f406/
#include<bits/stdc++.h>

using namespace std;
vector<vector<int>> make_graph(int sizes,int edgeNumbers){
    vector<vector<int>> graph(sizes+1);
    int nodeA,nodeB;
    for(int i=0;i<edgeNumbers;++i){
        cin>>nodeA>>nodeB;
        graph[nodeA].push_back(nodeB);
        graph[nodeB].push_back(nodeA);
    }
    return graph;

}
void dfs(int node,vector<vector<int>>&vec,vector<bool>&boo){

    boo[node] = true;

    for(auto it : vec[node]){
        if(boo[it] == false){

            dfs(it,vec,boo);

        }
    }

}

int main(){

    int n,m,k;

    cin>>n>>m>>k;

    int u,v;

    int count=0;

    vector<vector<int>> graph = make_graph(n,m);

    vector<bool>boo(n+1,false);


    for(int i=1;i<=n;i++){

        if(!boo[i]){

            count++;

            dfs(i,graph,boo);

        }

    }

    if(count>k){
        cout<< -1;
    }

    else{
        cout<<m-n+k;
    }

}