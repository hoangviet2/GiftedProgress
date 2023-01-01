#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxN = 2e5+7;
//int ans[maxN];
vector<int> gr[maxN];
int depth[maxN];
int ans = 0;
int x=0;
void dfs(int s, int p, int dep){
    for (auto i: gr[s]){
        if (i!=p){
            dfs(i,s,dep+1);
        }
    }
    if (dep>ans) ans = dep, x = s;
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
    dfs(1,0,0);
    dfs(x,0,0);
    cout<<ans;
}
int main()
{
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}