// Money Sums
#include <bits/stdc++.h>
using namespace std;
const int maxN = 10007;
int n;

vector<int> x(maxN);
void solve(){
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>x[i];
    }
    vector<vector<bool> > dp(107,vector<bool>(n*1000,false));
    dp[0][0] = true;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= (n*1000); j++) {
            dp[i][j] = dp[i-1][j];
            int left = j-x[i-1];
            if (left >= 0 && dp[i-1][left]) {
	            dp[i][j] = true;
            }
        }
    }

    vector<int> possible;
    for (int j = 1; j <= (n*1000); j++) {
        if (dp[n][j]) {
            possible.push_back(j);
        }
    }
    cout << possible.size() << endl;
    for (int v : possible) {
        cout << v << ' ';
    }
}

int main() {
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}