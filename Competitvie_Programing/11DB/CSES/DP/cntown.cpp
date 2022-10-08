// Counting Towers
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxN = 1e6;
const int MOD = 1e9+7;
ll dp[maxN+1];

void preprocess(){
    dp[1] = 2;
    dp[2] = 8;
    for(int i=3;i<=maxN;++i){
        dp[i] = ((6*dp[i-1] - 7*dp[i-2]) % MOD + MOD) % MOD;
    }
}

void solve(){
    int m;
    cin>>m;
    cout<<dp[m]<<"\n";

}
int main(){
#ifndef ONLINE_JUDGE

    freopen("input.txt", "r", stdin);

    freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    preprocess();
    while(t--){
        solve();
    }
    return 0;
}