// Company Queries I
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxN = 2e5+7;
vector<int> gr[maxN];
int depth[maxN];
void dfs(int node,int par){
    depth[node] = depth[par]+1;
    for(auto x:gr[node]){
        if(x!=par){
            dfs(x,node);
        }
    }
}
void solve(){
    int n;
    cin>>n;
    for(int i=0;i<n-1;++i){
        int a,b;
        cin>>a>>b;
        gr[a].push_back(b);
        gr[b].push_back(a);
    }
    //depth[1] = 0;
    dfs(1,0);
    
}

int main(){
#ifndef ONLINE_JUDGE

    freopen("input.txt", "r", stdin);

    freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);
    int t = 1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}