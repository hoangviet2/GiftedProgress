#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll P;
ll addmod(ll a,ll b){
    a %= P;
    b %= P;
    return (a+b)%P;
}
ll submod(ll a,ll b){
    a %= P;
    b %= P;
    return ((a-b)%P + P) % P;
}

ll mulmod(ll a,ll b){
    ll res = a;
    if(b==1){
        return a%P;
    }
    if(b%2){
        res = res+(mulmod(a,(b-1))+a)%P;
    }else{
        res = res+mulmod(a,b/2)%P;
    }
    return res;
    
}


ll powmod(ll a,ll b){
    ll res = 1;
    while(b){
        if(b & 1){
            res = mulmod(res,a);
        }
        b/=2;
        a = mulmod(a,a); 
    }
    return res;
}

ll T(ll a, ll k) {
	ll curr = 1;
	ll b = 0;
	ll res = 0;
	while (b <= k) {
        // T = n^b + prefix :<
		res = addmod(res, curr);
		curr = mulmod(curr, a);
		b++;
	}
	return res;
}
// can test :<
ll Can(ll n, ll a, ll p) {
	ll res = 0;
	for (ll i = 0; i <= n; i++) {
        //T (1) -> T(n) :<
		res = addmod(res, T(a, i));
	}
	return res;
}

// solve()
void solve(){
    ll n, a;
    cin>>a>>n>>P;
	if (n<=3007) {
		cout<<Can(n, a, P);
		return;
	}
	ll R = powmod(a-1, P-2);
	cout<<mulmod(submod(mulmod(submod(powmod(a, n+2), 1), R), n+2), R);

}

int main() {
#ifndef ONLINE_JUDGE

    freopen("input.txt", "r", stdin);

    freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    t = 1;
    while(t--){
        solve();
    }
}