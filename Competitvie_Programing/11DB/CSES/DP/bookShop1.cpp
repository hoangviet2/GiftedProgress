//Book Shop
#include <bits/stdc++.h>
using namespace std;
const int maxN = 1007;

int values[maxN], weights[maxN], maxWeight, n, mW[maxN][100001], dp[maxN][100001];

void solve(){
    cin>>n>>maxWeight;
    for(int i=0;i<n;++i){
        cin>>weights[i];
    }
    for(int i=0;i<n;++i){
        cin>>values[i];
    }
    memset(dp,0,sizeof(dp));
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= maxWeight; j++) {
            dp[i][j] = dp[i-1][j];
            int left = j-weights[i-1];
            if (left >= 0) {
	            dp[i][j] = max(dp[i][j], dp[i-1][left]+values[i-1]);
            }
        }
    }

    cout<<dp[n][maxWeight];

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