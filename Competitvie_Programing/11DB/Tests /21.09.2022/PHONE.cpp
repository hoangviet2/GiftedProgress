// Phone
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9+7;

void solve(){
    ll n,m;
    cin>>n>>m;
    vector<pair<ll,ll> > arr;
    for(int i=0;i<n;++i){
        ll a,b;
        cin>>a>>b;
        arr.push_back(make_pair(a,b));
    }
    sort(arr.begin(),arr.end());
    ll ans = 0;
    ans+=arr[0].second;
    for(int i=1;i<n;++i){
        if(arr[i].second>arr[i-1].second){
            ans += arr[i].second - arr[i-1].second;
        }
        
    }
    cout<<ans;
}

int main(){
// #ifndef ONLINE_JUDGE

//     freopen("PHONE.INP", "r", stdin);

//     freopen("PHONE.OUT", "w", stdout);

// #endif // ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}