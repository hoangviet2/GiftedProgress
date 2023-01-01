// Tree Matching
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxN = 2e5+7;
vector<int> gr[maxN];
int vis[maxN];
int ans=0;

// void dfs(int s, int p){
//     for (auto i: gr[s]){
//         if (i!=p){
//             dfs(i,s);
//             if (!vis[i] && !vis[s]){
//                 ans++;
//                 vis[i]=1;
//                 vis[s]=1;
//             }
//         }
//     }
// }
void dfs(int node,int par){
    for(auto x:gr[node]){
        if(x!=par){
            dfs(x,node);
            if(!vis[x] && !vis[node]){
                ans++;
                vis[x] = 1;
                vis[node] = 1;
            }
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
    dfs(1,0);
    cout<<ans;
}

int main(){
// #ifndef ONLINE_JUDGE

//     freopen("input.txt", "r", stdin);

//     freopen("output.txt", "w", stdout);

// #endif // ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);
    int t = 1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}