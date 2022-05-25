#include <bits/stdc++.h>
using namespace std;
int n,k;
vector<int> h,dp;
void readata(){
    cin>>n>>k;
    h.resize(n);
    for(int i=0;i<n;++i){
        cin>>h[i];
    }
    return;
}
void dpFunc(){
    dp.resize(n);
    dp[0] = 0;
    dp[1] = dp[0] + abs(h[1] - h[0]);
    for(int i = 2;i<n;++i){
        dp[i] = INT_MAX;
        for(int kk = 1; kk<=k && i-kk>=0 ;kk++){
            dp[i] = min(dp[i], dp[i-kk] + abs(h[i] - h[i-kk]));
        }
    }
    cout<<dp[n-1];
    return;
}
int main(){
    readata();
    dpFunc();
    return 0;
}