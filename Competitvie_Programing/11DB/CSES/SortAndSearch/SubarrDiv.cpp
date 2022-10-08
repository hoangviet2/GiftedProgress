// Subarray Divisibility
#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve(){
    int N;
	cin >> N;

	vector<ll> M(N);
	ll psums = 0;
	M[psums] = 1;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		psums += a;
		// Remember to account for negative sums
		M[(psums % N + N) % N]++;
	}

	ll ans = 0;
	for (ll x : M) {
		ans += x * (x - 1) / 2;
	}
	cout << ans << "\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}