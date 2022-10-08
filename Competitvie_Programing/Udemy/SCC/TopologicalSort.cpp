#include <bits/stdc++.h>
using namespace std;
const int maxN = 1e5+7;

vector<int> gr[maxN];
vector<int> order;
int vis[maxN];

void dfs(int cur,int par){
    vis[cur] = 1;
    for(auto node:gr[cur]){
        if(!vis[node]){
            dfs(node,cur);
        }
    }
    order.push_back(cur);
}

void solve(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;++i){
        int x,y;
        cin>>x>>y;
        gr[x].push_back(y);
    }
    
    for(int i=1;i<=n;++i){
        if(!vis[i]){
            dfs(i,0);
        }
    }

    reverse(order.begin(),order.end());

    for(auto x:order){
        cout<<x<<" ";
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
    int t=1;
    while(t--){
        solve()
    }
    return 0;
}