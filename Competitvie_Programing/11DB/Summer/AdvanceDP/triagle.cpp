#include <bits/stdc++.h>
using namespace std;
const int maxN = 107;
int a[maxN][maxN];
int dp[maxN][maxN];
int helper(int n){
    for(int i = 0; i < n; ++i){
		dp[n-1][i] = a[n-1][i];
	}

    for(int k = n-2; k >= 0; --k){
		for(int i = 0; i <= k; ++i){
			dp[k][i] = max(dp[k+1][i],dp[k+1][i+1])+a[k][i];
		}
	}

	return dp[0][0];
}

void solve(){
    int n;
    cin>>n;
    for(int i =0;i<n;++i){
        for(int j=0;j<=i;++j){
            cin>>a[i][j];
        }
    }
    cout<<helper(n)<<"\n";
}

int main(){
// #ifndef ONLINE_JUDGE

//     freopen("input.txt", "r", stdin);

//     freopen("output.txt", "w", stdout);

// #endif // ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //cout<<"Hello world"<<"\n";
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}