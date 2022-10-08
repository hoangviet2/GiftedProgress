#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+1;
vector<int> graph[maxn];
int directions[maxn];
int m,n;

void bfs(int a[]){
    queue<int> q;
    directions[1] = 0;
    q.push(1);
    while(!q.empty()){
        int t=q.front();
        q.pop();
        for(int x:graph[t]){
            if(directions[x]==-1){
                directions[x]= directions[t]+1;
                q.push(x);
            }
            // for(int i=0;i<n;++i){
            //     cout<<directions[i]<<" ";
            // }
            // cout<<"\n";
        }
    }
}

int main(){
#ifndef ONLINE_JUDGE

    freopen("input.txt", "r", stdin);

    freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //cout<<"Hello world"<<"\n";
    cin>>n>>m;
    for(int i=0;i<m;++i){
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    memset(directions,-1,sizeof(directions));
    bfs(directions);
    cout<<directions[n]-1;
    return 0;
}