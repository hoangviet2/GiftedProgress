// Elevator Rides
#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    int n;
    ll maxW;
    cin>>n>>maxW;
    vector<ll> people(n);
    for(int i=0;i<n;++i){
        cin>>people[i];
    }
    vector<pair<ll,ll>> dp(1<<n); // (numberOfRides, totalWeightOfLastRide)
    dp[0] = {1, 0};
    for (int mask = 1; mask < (1<<n); mask++) {
        pair<ll, ll> bestResult = {INT_MAX, INT_MAX};
        for (int i = 0; i < n; i++) {
            if (((1 << i) & mask) == 0){
                continue;
            }
            auto res = dp[(1 << i) ^ mask];
            if (res.second + people[i] <= maxW) {
                res.second += people[i];
            } else {
                res.first += 1;
                res.second = people[i];
            }
            bestResult = min(bestResult, res);
        }
        dp[mask] = bestResult;
    }
    cout << dp[(1<<n) - 1].first;
}

int main(){
#ifndef ONLINE_JUDGE

    freopen("input.txt", "r", stdin);

    freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}