#include <bits/stdc++.h>
using namespace std;
const int maxN = 1e5+7;

vector<int> g[maxN];
int vis[maxN];
bool cycle = false;

void dfs(int cur,int par){
    cout<<cur<<"\n";
    vis[cur] = true;
    for(auto x:g[cur]){
        if(!vis[x]){
            dfs(x,cur);
        }else if(x!=par){
            // backedges
            cout<<cur<<" "<<x<<"\n";
            cycle = true;
        }
    }
}

void solve(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;++i){
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for(int i=1;i<=n;++i){
        if(!vis[i]){
            //cout<<i<<":"<<"\n";
            dfs(i,0);
        }
    }
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
