#include<bits/stdc++.h>

#define int long long int
#define F first
#define S second
#define pb push_back
using namespace std;
const int mod = 1e9+7;
const int N = 101;
int n,k;
int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    cin>>n>>k;
    int value[n+1];
    for(int i=1;i<=n;++i){
        cin>>value[i];
    }
    int dp[n+1][k+1];
    memset(dp,0,sizeof(dp));
    dp[0][0] = 1;
    // for(int i=1; i<=n ;++i){
    //     for(int j=0; j<=k ;++j){
    //         for(int kk=0; kk<=min(value[i],j); ++kk){
    //             dp[i][j] += dp[i-1][j-(kk)];
    //         }
    //     }
    // }
    
    // for(int i=0; i<=n ;++i){
    //     for(int j=0; j<=k ;++j){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }

    //cout<<"\n";
    //memset(dp,0,sizeof(dp));
    //dp[0][0] = 1;
    for(int i=1; i<=n ;++i){
        for(int j=1; j<=k ;++j){
            dp[i-1][j] += dp[i-1][j-1];
        }
        for(int j=0; j<=k ;++j){
            dp[i][j] = dp[i-1][j];
            if(j-value[i]>0){
                dp[i][j] -= dp[i-1][j-value[i]-1];
            }
            dp[i][j] = ((dp[i][j]%mod) + mod) %mod;
        }
    }

    // for(int i=0; i<=n ;++i){
    //     for(int j=0; j<=k ;++j){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    cout<<dp[n][k];
	return 0;
}