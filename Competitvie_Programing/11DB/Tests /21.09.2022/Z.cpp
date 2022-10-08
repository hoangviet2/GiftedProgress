// Z
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9+7;
const int maxN = 6007;
vector<int> gr[maxN];
ll a[maxN];

ll dfs(int node,int par){
    ll ans = 0;
    for(auto x:gr[node]){
        if(x!=par){
            if(a[node]<a[x]){
                ans = max(ans,dfs(x,node)+1);
            }
        }
    }
    return ans;
}

void solve(){
    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>a[i+1];
    }
    for(int i=0;i<n-1;++i){
        int a,b;
        cin>>a>>b;
        gr[a].push_back(b);
        gr[b].push_back(a);
    }
    ll ans = 0;
    for(int i=1;i<=n;++i){
        ans = max(ans,dfs(i,0));
    }
    cout<<ans+1;
}

int main(){
#ifndef ONLINE_JUDGE

    freopen("Z.INP", "r", stdin);

    freopen("Z.OUT", "w", stdout);

#endif // ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}