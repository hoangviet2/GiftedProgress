//
//  main.cpp
//  Xcode
//
//  Created by Viet Hoang on 12/12/2021.
//

// question link: https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/practice-problems/algorithm/little-shino-and-k-ancestor-57fdef57/discussion/dfs-solution-d710284f/
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;


 

vector<int>Graph[1000001],c[1000001];

int visited[1000001]={0};

int b[1000001]={0};

int answer[1000001]={0};


 

void dfs(int s,int k){

    visited[s]=1;


 

    if(c[b[s]].size()>=k){

        int size=c[b[s]].size();

        answer[s]=c[b[s]][size-k];

    }

    else

    answer[s]=-1;

    c[b[s]].push_back(s);

    

 

    for(int i=0;i<Graph[s].size();i++){

        if(visited[Graph[s][i]]==0){

            dfs(Graph[s][i],k);

        }

    }

    if(c[b[s]].size()!=0){
        c[b[s]].pop_back();
    }

}

int main(){

    ios_base::sync_with_stdio(false);

    cin.tie(NULL);
    cout.tie(NULL);


    freopen("input.inp", "r", stdin);
    
    int n,k;

    cin>>n>>k;

 

    int i;

    for(i=1;i<=n;i++){

        cin>>b[i];

    }


 

    for(i=1;i<n;i++){

        int x,y;

        cin>>x>>y;

        Graph[x].push_back(y);

        Graph[y].push_back(x);

    }

    dfs(1,k);


 

    for(i=1;i<=n;i++){

        cout<<answer[i]<<" ";

    }

    

}
