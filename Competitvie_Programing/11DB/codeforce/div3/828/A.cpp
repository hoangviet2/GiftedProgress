// 
#include <bits/stdc++.h>
using namespace std;
string s;
bool isfall = false;
#define ll long long
void dfs(int node,int par,vector<int> &gr){
    for(auto x:gr[node]){
        if(){
            
        }
    }
}
void solve(){
    int n;
    cin>>n;
    vector<int> gr(n);
    for(int i=0;i<n;++i){
        int a;
        cin>>a;
        gr[a].push_back(i);
    }
    cin>>s;
    for(int i=0;i<n;++i){
        if(!visited[i]){
            dfs(i,0);
        }
    }
    
}

int main(){
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