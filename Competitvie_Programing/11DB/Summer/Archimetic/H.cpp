// Prime Factor
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int  maxN = 50007;
ll p[10000];
ll s = 0;
bool sieve[maxN+1];

void primeSieve(){

	sieve[0] = true;
	sieve[1] = true;
	
	for (long long i = 2; i <= maxN; i++) {
		if (!sieve[i]) {
			p[s++] = i;
			for (long long j = i * i; j <= maxN; j += i) {
				sieve[j] = true;
			}
		}
	}

}


void solve(){
    ll a;
    while(cin>>a){
        if(a==0){
            return;
        }
        ll m = 0;
        ll v[50];
        ll num = a;
        if (a < 0) {
			v[m++] = -1;
			a = -a;
		}
        for (ll i = 0; i < s; i++) {
			if (a == 1) break;
			while (a % p[i] == 0) {
				v[m++] = p[i];
				a /= p[i];
			}
		}
		if (a > 1){
            v[m++] = a;
        }
        cout<<num<<" = "<<v[0];
        for(ll i=1;i<m;++i){
            cout<<" x "<<v[i];
        }
        cout<<"\n";
    }
}

int main(){
// #ifndef ONLINE_JUDGE

//     freopen("input.txt", "r", stdin);

//     freopen("output.txt", "w", stdout);

// #endif // ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    primeSieve();
    while(t--){
        solve();
    }
    return 0;
}