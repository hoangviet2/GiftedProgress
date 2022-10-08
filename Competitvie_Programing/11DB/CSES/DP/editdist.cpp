// Edit Distance
#include <bits/stdc++.h>
using namespace std;
const int maxN = 5007;
vector<vector<int>> dp(maxN,vector<int> (maxN,1e9));

void solve(){
    string a,b;
    cin>>a>>b;
    dp[0][0] = 0;
    for(int i=0;i<=a.size();++i){
        for(int j=0;j<=b.size();++j){
            if(i){
	            dp[i][j] = min(dp[i][j], dp[i-1][j]+1);
            }
            if(j){
	            dp[i][j] = min(dp[i][j], dp[i][j-1]+1);
            }
            if(i && j){
	            dp[i][j] = min(dp[i][j], dp[i-1][j-1]+(a[i-1] != b[j-1]));
            }
        }
    }
    cout<<dp[a.size()][b.size()];
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