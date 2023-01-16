//
//  theFlightPlan.cpp
//  BFS
//
//  Created by Hoang Viet on 11/11/2021.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
vector<int>graphs[1001];

int v[1001]={0},f=0;

int d[1001]={0};

int pa[1001]={0};
void bfs(int x,int y,int n){

    v[x]=1;

 

    queue<int>queue;

    queue.push(x);

    if(x==y){

        cout<<"1"<<"\n";

        cout<<x;

        return;

    }


 

    while(!queue.empty()){

        int z=queue.front();

        queue.pop();


 

        if(z==y){

            cout<<d[z]+1<<"\n";

            vector<int>k;

            for(int i=y;i>0;i=pa[i]){

                k.push_back(i);

            }

            reverse(k.begin(),k.end());

            for(auto it:k)
                cout<<it<<" ";

            return;

        }


 

        for(int i=0;i<graphs[z].size();i++){

            if(v[graphs[z][i]]==0){

                d[graphs[z][i]]=d[z]+1;

                v[graphs[z][i]]=1;

                pa[graphs[z][i]]=z;

                queue.push(graphs[z][i]);

            }

        }


 

    }

}

int mainTFP(){

    int n,m,t,c;

    cin>>n>>m>>t>>c;


 

    int u,v;

    int i;

    for(i=0;i<m;i++){

        cin>>u>>v;

        graphs[u].push_back(v);

        graphs[v].push_back(u);

    }


 

    for(i=1;i<=n;i++){

        sort(graphs[i].begin(),graphs[i].end());

    }

    int x,y;

    cin>>x>>y;


 

    bfs(x,y,n);
    return 0;
}
