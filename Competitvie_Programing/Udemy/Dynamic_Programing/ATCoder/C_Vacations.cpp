#include <bits/stdc++.h>
const int N = 1e5 +1;
using namespace std;
int dp[N][3], cost[N][3];

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        for(int j=0;j<3;++j){
            cin>>cost[i][j];
        }
    }
    dp[0][0] = cost[0][0];
    dp[0][1] = cost[0][1];
    dp[0][2] = cost[0][2];

    for(int i=1;i<n;++i){
        for(int j=0;j<3;++j){
            for(int jj=0;jj<3;++jj){
                if(j!=jj){
                    dp[i][j] = max(dp[i][j],dp[i-1][jj] + cost[i][j]);
                }
            }
        }
    }
    int ans = INT_MIN;
    for(int i=0;i<n;++i){
        for(int j=0;j<3;++j){
            ans = max(ans,dp[i][j]);
        }
    }
    cout<<ans;
    return 0;
}