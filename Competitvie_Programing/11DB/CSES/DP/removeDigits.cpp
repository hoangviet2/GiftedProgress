// Removing Digits
#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int> dp(n+1,1e9);
    dp[0] = 0;
    for(int i = 1;i<=n;++i){
        for(auto c: to_string(i)){
            dp[i] = min(dp[i],dp[i-(c-'0')]+1);
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