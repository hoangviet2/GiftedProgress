#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxN = 2e5+7;
int ans[maxN];
vector<int> gr[maxN];
void dfs(int node,int par){
    int preAns = 0;
    for(auto x:gr[node]){
        if(x!=par){
            dfs(x,node);
            preAns += (1+ans[x]);
        }
    }
    ans[node] = preAns;
}
void solve(){
    int n;
    cin>>n;
    for(int i=2;i<=n;++i){
        int x;
        cin>>x;
        gr[i].push_back(x);
        gr[x].push_back(i);
    }
    dfs(1,0);
    for(int i=1;i<=n;++i){
        cout<<ans[i]<<" ";
    }
}
int main()
{
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}