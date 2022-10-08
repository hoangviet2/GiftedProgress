// Bit Strings
#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;
#define ll  long long

ll power(ll x, ll y){
    ll temp;
    if (y == 0){
        return 1;
    }
    temp = power(x, y / 2);
    if (y % 2 == 0){
        return (temp * temp)%MOD;
    }else{
        return (x * temp * temp)%MOD;
    }
}

void solve(){
    ll n;
    cin>>n;
    cout<<power(2,n)%MOD;
}

int main(){
// #ifndef ONLINE_JUDGE

//     freopen("input.txt", "r", stdin);

//     freopen("output.txt", "w", stdout);

// #endif // ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}