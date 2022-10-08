// brute force of LCA
// O(n)
#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e5+7;
const int maxM = 20;

vector<int> g[maxN];
int Deepth[maxN], Par[maxN][maxM];

void DFS(int cur,int par){
    //Par[cur] = par;
    Deepth[cur] = Deepth[par]+1;

    Par[cur][0] = par;

    for(int j = 1; j<maxM;++j){
        Par[cur][j] = Par[Par[cur][j-1]][j-1];
    }

    for(auto x:g[cur]){
        if(x!=par){
            DFS(x,cur);
        }
    }
}

int LCA(int u,int v){
    if(u==v){
        return u;
    }
    if(Deepth[u] < Deepth[v]){
        swap(u,v);
    }
    int diff = abs(Deepth[u]-Deepth[v]);
    for(int j=maxM-1;j>=0;--j){
        if((diff>>j)&1){
            u = Par[u][j];
        }
    }
    for(int j = maxM-1;j>=0;--j){
        if(Par[u][j] != Par[v][j]){
            u = Par[u][j];
            v = Par[v][j];
        }
    }
    return Par[u][0];
}

void solve(){
    int n;
    cin>>n;
    for(int i=1;i<n;++i){
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    DFS(1,0);
//    for(int i=1;i<=n;++i){
//        cout<<i<<" ";
//    }
//    cout<<"\n";
//    for(int i=1;i<=n;++i){
//        cout<<Deepth[i]<<" ";
//    }
//    cout<<"\n";
//    for(int i=1;i<=n;++i){
//        cout<<Par[i]<<" ";
//    }
    cout<<LCA(4, 6);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    t = 1;
    while(t--){
        solve();
    }
    return 0;
}
