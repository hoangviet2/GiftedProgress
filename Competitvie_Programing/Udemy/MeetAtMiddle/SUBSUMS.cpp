#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<ll> sumProduct(vector<ll> a){
    ll n = a.size();
    vector<ll> res;
    for(ll i=0;i<(1<<n);++i){
        ll sum = 0;
        for(ll j=0;j<n;++j){
            if((i>>j) & 1){
                sum+=a[j];
            }
        }
        res.push_back(sum);
    }
    return res;
}

void solve(){
    ll a,b,n;
    cin>>n>>a>>b;
    ll arr[n];
    for(ll i=0;i<n;++i){
        cin>>arr[i];
    }
    vector<ll> left;
    vector<ll> right;
    for(ll i=0;i<n;++i){
        if(i<=n/2){
            left.push_back(arr[i]);
        }else{
            right.push_back(arr[i]);
        }
    }
    vector<ll> leftSum = sumProduct(left);
    vector<ll> rightSum = sumProduct(right);
    sort(rightSum.begin(),rightSum.end());
    ll ans = 0;
    for(ll i=0;i<leftSum.size();++i){
        ans += upper_bound(rightSum.begin(),rightSum.end(),b-leftSum[i])- 
                lower_bound(rightSum.begin(),rightSum.end(),a-leftSum[i]);
    }
    cout<<ans;
}

int32_t main(){
#ifndef ONLINE_JUDGE

    freopen("input.txt", "r", stdin);

    freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    t = 1;
    while(t--){
        solve();
    }
    return 0;
}