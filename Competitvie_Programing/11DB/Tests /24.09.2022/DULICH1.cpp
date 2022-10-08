// DULICH
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxN = 5000;
map<pair<int,int>,int> values;
vector<int> gr[maxN];
ll ans = 0;
void solve(){
    int n,edges,p;
    for(int i=0;i<edges;++i){
        int a,b;
        cin>>a>>b;
        gr[a].push_back(b);
    }
    //dfs(n,0);
    cout<<-1;
}

int main(){
#ifndef ONLINE_JUDGE

    freopen("DULICH.INP", "r", stdin);

    freopen("DULICH.OUT", "w", stdout);

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