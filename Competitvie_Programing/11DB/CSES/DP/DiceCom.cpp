// Dice Combinations
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9+7;
void solve(){
    int n;
    cin>>n;
    vector<int> dp(n+7,0);
    dp[0] = 1;
    for(int i=1;i<=n;++i){
        for (int j = 1; j <= 6 && i-j >= 0; j++) {
            (dp[i] += dp[i-j]) %= MOD;
        }
    }
    cout<<dp[n];
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
    while(t--){
        solve();
    }
    return 0;
}