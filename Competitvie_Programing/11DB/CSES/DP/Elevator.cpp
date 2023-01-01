// Elevator Rides
#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    int n;
    ll maxW;
    cin>>n>>maxW;
    int values[n];
    for(int i=0;i<n;++i){
        cin>>values[i];
    }
    vector<pair<ll,ll> > dp(1<<n);// numberofrides, weight of the last ride
    dp[0] = make_pair(1,0);
    for(int mask=1;mask<(1<<n);++mask){ // gen all masks
        pair<ll,ll> bestChoice = make_pair(INT_MAX,INT_MAX);
        for(int i=0;i<n;++i){
            if( ((1 << i) & mask) == 0){
                continue;
            }
            auto res = dp[ (1<<i) ^ mask];
            if(res.second + values[i] <= maxW){
                res.second += values[i];
            }else{
                res.first += 1;
                res.second = values[i];
            }
            bestChoice = min(bestChoice,res);
        }
        dp[mask] = bestChoice;
    }
    cout<<dp[(1<<n) - 1].first<<"\n";
}

int main(){
#ifndef ONLINE_JUDGE

    freopen("input.txt", "r", stdin);

    freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}