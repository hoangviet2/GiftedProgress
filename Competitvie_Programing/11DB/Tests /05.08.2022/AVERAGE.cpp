#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    ll n;
    ll k;
    cin>>n>>k;
    ll a[n];
    for(int i=0;i<n;++i){
        cin>>a[i];
    }
    ll cnt = 0;
    map<ll,ll> mapple;
    ll suffix = 0;
    for(int i=0;i<n;++i){
        suffix += a[i]-k;
        if(suffix == 0){
            ++cnt;
        }
        cnt += mapple[suffix];
        mapple[suffix]++;
    }
    cout<<cnt;
}
int main(){
#ifndef ONLINE_JUDGE
    freopen("AVERAGE.INP", "r", stdin);
    freopen("AVERAGE.OUT", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    t = 1;
    while(t--){
        solve();
    }
    return 0;
}