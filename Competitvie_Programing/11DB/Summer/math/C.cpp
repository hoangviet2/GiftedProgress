#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 10000007;
ll powr(ll a,ll n){
    ll ans = 1;
    while(n>0){
        if(n%2==1){
            ans *= a;
            ans %= mod;
        }
        a *= a;
        a %= mod;
        n /= 2;
    }
    return ans;
}

int main(){
#ifndef ONLINE_JUDGE

    freopen("input.txt", "r", stdin);

    freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,k;
    while(cin>>n>>k){
        if(n==0 && k==0){
            return 0;
        }
        ll S1 = (2*powr(n-1,k))%mod;
        ll S2 = powr(n,k);
        ll P1 = (2*powr(n-1,n-1))%mod;
        ll P2 = powr(n,n);
        cout<<(S1+S2+P1+P2) % mod<<"\n";
    }
    return 0;
}