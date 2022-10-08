// Building Roads
#include <bits/stdc++.h>
using namespace std;

const int maxN = 200007;
vector<int> gr[maxN];
bool vis[maxN];
void dfs(int node){
    vis[node] = true;
    for(auto x:gr[node]){
        if(!vis[x]){
            dfs(x);
        }
    }
}

void solve(){
    int n,m;
    cin>>n>>m;
    vector<int> bridges;
    for(int i=0;i<m;++i){
        int a,b;
        cin>>a>>b;
        gr[a].push_back(b);
        gr[b].push_back(a);
    }
    for(int i=1;i<=n;++i){
        if(!vis[i]){
            bridges.push_back(i);
            dfs(i);
        }
    }
    cout<<bridges.size()-1<<"\n";
    for(int i=0;i<bridges.size()-1;++i){
        cout<<bridges[i]<<" "<<bridges[i+1]<<"\n";
    }
}

int main(){
// #ifndef ONLINE_JUDGE

//     freopen("input.txt", "r", stdin);

//     freopen("output.txt", "w", stdout);

// #endif // ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}