// Grid Paths
#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;

void solve(){
    int n;
    cin>>n;
    char a[n][n];
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            cin>>a[i][j];
        }
    }
    // dp[i][j] ways to get square i,j
    int dp[n][n];
    memset(dp,0,sizeof(dp));
    dp[0][0] = 1;
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            if(a[i][j] == '.'){
                if(i>0){
                    (dp[i][j]+=dp[i-1][j])%=MOD;
                }
                if(j>0){
                    (dp[i][j]+=dp[i][j-1])%=MOD;
                }
            }else{
                dp[i][j] = 0;
            }
        }
    }
    cout<<dp[n-1][n-1];
}

int main(){
#ifndef ONLINE_JUDGE

    freopen("input.txt", "r", stdin);

    freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //cout<<"Hello world"<<"\n";
    int t = 1;
    while (t--){
        solve();
    }
    
    return 0;
}