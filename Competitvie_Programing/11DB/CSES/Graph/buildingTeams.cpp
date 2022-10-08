// Building Teams
#include <bits/stdc++.h>
using namespace std;
int n,m;
const int maxN = 200007;
vector<int> gr[maxN];
bool vis[maxN];
bool ans[maxN];
bool possible;

void dfs(int node,int par){
    for(auto x:gr[node]){
        if(x!=par){
            if(!vis[x]){
                ans[x] = !ans[node];
                vis[x] = true;
                dfs(x,node);
            }else{
                if(ans[x] == ans[node]){
                    possible = false;
                }
            }
        }
    }
}

void solve(){
    //int n,m;
    cin>>n>>m;
    for(int i=0;i<m;++i){
        int a,b;
        cin>>a>>b;
        gr[a].push_back(b);
        gr[b].push_back(a);
    }
    possible = true;
    for(int i=1;i<=n;++i){
        if(!vis[i]){
            dfs(i,0);
        }
    }
    if(!possible){
        cout<<"IMPOSSIBLE";
        return;
    }
    for(int i=1;i<=n;++i){
        if(ans[i]){
            cout<<1<<" ";
        }else{
            cout<<2<<" ";
        }
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