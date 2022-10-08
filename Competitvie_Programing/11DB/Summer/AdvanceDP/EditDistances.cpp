#include <bits/stdc++.h>
using namespace std;

int minDistance(string a, string b) {
    int m = a.length();
    int n = b.length();
    int dp[a.length()+1][b.length()+1];
    for (int i = 0; i <= m; i++) {
        dp[i][0] = i;
    }
    for (int j = 0; j <= n; j++) {
        dp[0][j] = j;
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1]) + 1;
            }
        }
    }
    return dp[m][n];
}

void solve(){
    string s1,s2;
    cin>>s1>>s2;
    cout<<minDistance(s1,s2)<<"\n";
}
int main(){
// #ifndef ONLINE_JUDGE

//     freopen("input.txt", "r", stdin);

//     freopen("output.txt", "w", stdout);

// #endif // ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //cout<<"Hello world"<<"\n";
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}