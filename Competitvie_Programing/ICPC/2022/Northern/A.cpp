// 
#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll a[10] = {1,1,2,6,24,120,720,5040,40320,362880};
ll ans = 0;
void solve(){
    int n;
    cin>>n;
    while(n){
        ans+=a[n%10];
        n/=10;
    }
    cout<<ans<<"\n";
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt","w", stdout);
#endif // ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);
    int t = 1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}