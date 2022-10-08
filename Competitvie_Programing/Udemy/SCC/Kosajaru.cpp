// find circle
#include <bits/stdc++.h>
using namespace std;
const int maxN = 1e5+1;

vector<int> gr[maxN], grr[maxN];
int vis[maxN] , col[maxN];
vector<int> order;
vector<int> componentss[maxN];
// topological sort
void dfs1(int source){
    vis[source] = 1;
    for(auto x:gr[source]){
        if(!vis[x]){
            dfs1(x);
        }
    }
    order.push_back(source);
}

void dfs2(int source, int components){
    vis[source] = 1;
    col[source] = components;
    componentss[components].push_back(source);
    for(auto x:grr[source]){
        if(!vis[x]){
            dfs2(x,components);
        }
    }
    //order.push_back(source);
}

void solve(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;++i){
        int x,y;
        cin>>x>>y;
        gr[x].push_back(y);
        grr[y].push_back(x);
    }

    for(int i=1;i<=n;++i){
        if(!vis[i]){
            dfs1(i);
        }
    }
    reverse(order.begin(),order.end());
    memset(vis,0,sizeof(vis));
    int components = 1;
    for(auto x:order){
        if(!vis[x]){
            dfs2(x,components++);
        }
    }

    for(int i=1;i<=n;++i){
        cout<<i<<" "<<col[i]<<"\n";
    }

    cout<<"total strongly components: "<<components<<"\n";
}

int main(){
#ifndef ONLINE_JUDGE

    freopen("input.txt", "r", stdin);

    freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}