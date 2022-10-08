// Minimizing Coins
#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n,target;
    cin>>n>>target;
    int c[n];
    for(int i=0;i<n;++i){
        cin>>c[i];
    }

    vector<int> dp(target+1,1e9);
    dp[0] = 0;
    for (int i = 1; i <= target; i++) {
        for (int j = 0; j < n; j++) {
            if (i-c[j] >= 0) {
	            dp[i] = min(dp[i], dp[i-c[j]]+1);
            }
        }
    }
  cout<<(dp[target] == 1e9 ? -1 : dp[target])<< '\n';
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