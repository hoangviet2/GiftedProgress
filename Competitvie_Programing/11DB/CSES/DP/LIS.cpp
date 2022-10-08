// Increasing Subsequence
#include <bits/stdc++.h>
using namespace std;
const int maxN = 200007;
int dp[maxN];

void solve(){
    int n;
    cin>>n;
    vector<int> dp;
    for(int i=0;i<n;++i){
        int x;
        cin>>x;
        auto it = lower_bound(dp.begin(),dp.end(),x);
        if(it == dp.end()){
            dp.push_back(x);
        }else{
            *it = x;
        }
    }
    cout<<dp.size();
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