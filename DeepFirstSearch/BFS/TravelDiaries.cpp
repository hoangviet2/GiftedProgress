#include<queue>
#include <iostream>
#include <utility>
using namespace std;

int level[1001][1001];

char a[1001][1001];

int sum[1001][1001];

bool vis[1001][1001];

int dx[4]={0,0,1,-1};

int dy[4]={1,-1,0,0};

int n,m,mx=0;

bool check(int x,int y){
    if(x<0 || y<0 || x>=n || y>=m || a[x][y]==0 || a[x][y]==2 || vis[x][y]==true){
        return false;
    }
    return true;
}

void bfs(queue<pair<int,int>>q){

    while(!q.empty()){

        int f=q.front().first;

        int p=q.front().second;

        q.pop();

        //cout<<f<<" "<<p<<"\n";

        for(int i=0;i<4;i++){

            int x1=f+dx[i];

            int y1=p+dy[i];

            if(check(x1,y1)){

 

                q.push(make_pair(x1,y1));

                a[x1][y1]=2;

                level[x1][y1]=level[f][p]+1;

                vis[x1][y1]=true;

                //cout<<level[x1][y1]<<" ";
            }

        }

}


 

}

int mainTD(){

    int x,x2,y,y2,k,l;

    cin>>n>>m;

    memset(level,0,sizeof(level));

    memset(vis,false,sizeof(vis));

    queue<pair<int,int>>q;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){

            int u;

            cin>>u;

            a[i][j]=u;

            if(u==2){

 

                q.push(make_pair(i,j)) ;

                vis[i][j]=true;
            }

        }

    }


 

 

    bfs(q);

    for(int i=0;i<n;++i){

        for(int j=0;j<m;++j){
            if(a[i][j]==1){
                cout<<"-1\n";
                return 0;

            }

        }

    }

    for(int i=0;i<n;i++){

        for(int j=0;j<m;j++){

            mx=max(mx,level[i][j]);

        }

    }

 

    cout<<mx<<"\n";


 
    return 0;
}

