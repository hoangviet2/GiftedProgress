#include <bits/stdc++.h>
using namespace std;
const int maxN = 2e5+7;
int depth [maxN];
vector<int> g[maxN];
void dfs(int cur,int par){
    depth[cur] = depth[par]+1;
    for(auto x:g[cur]){
        if(x!=par){
            dfs(x,cur);
        }
    }
}

void solve(){
    int n,k;
    cin>>n>>k;
    int x,y;
    for(int i=0;i<n-1;++i){
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1,0);
    sort(depth,depth+maxN);
    int ans = 0;
    for(int i=n-k;i<n;++i){
        ans += depth[i];
    }
    cout<<ans;
    return;
}

int main(){
#ifndef ONLINE_JUDGE

    freopen("input.txt", "r", stdin);

    freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    t = 1;
    while(t--){
        solve();
    }
    return 0;
}
