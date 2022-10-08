#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxN = 1e5+7;
ll dp[maxN];

ll helper(ll n){
    if(n==0){
        return 0;
    }
    ll &ans = dp[n];
    if(ans != -1){
        return ans;
    }
    ans = INT_MAX;
    for(ll i=1;i*i*i<=n;++i){
        ans = min(ans,1+helper(n-(i*i*i)));
    }
    return dp[n] = ans;
}

void solve(){
    int n;
    int cases = 1;
    while(cin>>n){
        cout<<"Case #"<<cases<<": "<<helper(n)<<"\n";
        ++cases;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //cout<<"Hello world"<<"\n";
    int t;
    t = 1;
    memset(dp,-1,sizeof(dp));
    while (t--){
        solve();
    }
    
    return 0;
}