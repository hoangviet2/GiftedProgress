#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n,m;
    cin>>n>>m;
    int ans = INT_MIN;
    for(int i=0;i<n-1;++i){
        int a,b,c;
        cin>>a>>b>>c;
        ans = max(ans,c);
    }
    cout<<ans;
}

int main(){
#ifndef ONLINE_JUDGE

    freopen("SERVICE.INP", "r", stdin);

    freopen("SERVICE.OUT", "w", stdout);

#endif // ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}