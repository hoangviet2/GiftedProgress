#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxN = 21;

//int masks[maxN][maxN];
int a[maxN][maxN];
ll dp[1<<maxN];

void solve(){
    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            cin>>a[i][j];
        }
    }
    for(int mask=1;mask<(1<<n);++mask){
        // masks[0][i] = (1<<i);
        vector<int> b;
        for (int i=0;i<n;i++){
            if((mask>>i)&1){
                b.push_back(i);
            }
        }
        int pos = b.size();
        for (auto &i:b){
            int pre_mask = mask&(~(1<<i));
            dp[mask] = max (dp[mask],(dp[pre_mask]+a[pos-1][i]));
        }
    }
    cout<<dp[(1<<n)-1];
}

int main(){
// #ifndef ONLINE_JUDGE

//     freopen("input.txt", "r", stdin);

//     freopen("output.txt", "w", stdout);

// #endif // ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    while (t--){
        solve();
    }
    return 0;
}