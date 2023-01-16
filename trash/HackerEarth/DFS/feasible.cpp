// Question link: https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/practice-problems/algorithm/feasible-relations/
#include<bits/stdc++.h>

using namespace std;

const int N=1e6+9;

vector<int> adj[N];

int visited[N],cc[N],d;


 

void dfs(int node){

    cc[node]=d;

    visited[node]=1;

    for(auto child:adj[node]){
        if(visited[child]==0){

            dfs(child);

        }

    }

}


 

int main(){

    ios_base::sync_with_stdio(0), cin.tie(0);

    short t; cin>>t;

    while(t--){

        memset(adj,0,sizeof(adj));

        memset(visited,0,sizeof(visited));

        memset(cc,0,sizeof(cc));

        d=0;

        int n,k; cin>>n>>k;

        map<int,vector<int> > m;

        for(int i=1;i<=k;i++){

            int x,y;string r;

            cin>>x>>r>>y;

        if(r=="="){
            adj[x].push_back(y), adj[y].push_back(x);
        }

        else{

            m[x].push_back(y);

        }

    }

    for(int i=1;i<=n;i++){

        if(visited[i]==0){

            d++;

            dfs(i);

        }

    }

    for(auto it:m){

        int key=it.first;

        for(auto value:it.second){

            if(cc[key]==cc[value]){

                cout<<"NO\n";

                goto last;

            }

        }

    }

    cout<<"YES\n";

    last:;

    }

}