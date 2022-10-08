#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll m,n,mods;
ll memo[1007][1007];
ll helper(int i,int j){
    if(i>m||i>m||j>n||i>n){
        return 0;
    }
    if(i==m && j==n){
        return 1;
    }
    ll &ans = memo[i][j];
    if(ans!=-1){
        return ans;
    }
    ans = 0;
    
    ans += helper(i+1,j)%mods + helper(i,j+1)%mods;
    return ans%mods;
}
void solve(){
    cin>>m>>n>>mods;
    cout<<helper(0,0)<<'\n';
}

int main(){
// #ifndef ONLINE_JUDGE

//     freopen("input.txt", "r", stdin);

//     freopen("output.txt", "w", stdout);

// #endif // ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //cout<<"Hello world"<<"\n";
    int t = 1;
    cin>>t;
    while(t--){
        memset(memo,-1,sizeof(memo));
        solve();
    }
    return 0;
}