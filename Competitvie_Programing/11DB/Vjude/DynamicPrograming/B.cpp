#include <bits/stdc++.h>
using namespace std;
int n, m, k;
const int maxN = 5001;
long long a[maxN], dp[maxN][maxN];
int main(){
// #ifndef ONLINE_JUDGE

//     freopen("input.txt", "r", stdin);

//     freopen("output.txt", "w", stdout);

// #endif // ONLINE_JUDGE
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] += a[i - 1];
    }
  
    for (int i = m; i <= n; i++){
        for (int j = 1; j <= k; j++){
            dp[i][j] = max(dp[i - 1][j], dp[i - m][j - 1] + a[i] - a[i - m]);
        }
    }
    cout << dp[n][k] << "\n";
}