#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
 
void StretfordEnd() {
	int n;
	cin >> n;
	vector<ll> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	ll even = a[0], odd = a[1];
	for (int i = 0; i < n; i++) {
		if (i % 2 == 0) even = __gcd(even, a[i]);
		else odd = __gcd(odd, a[i]);
	}
	if (even == 1 && odd == 1) {
		cout << 0 << "\n";
		return;
	}
	if (even == odd) {
		cout << 0 << "\n";
		return;
	}
	bool e = true, o = true;
	for (int i = 0; i < n; i++) {
		if (i % 2 == 0 && a[i] % odd == 0) o = false;
		if (i % 2 == 1 && a[i] % even == 0) e = false;
	}
	if (!e && !o) {
		cout << 0 << "\n";
		return;
	}
	if (!e) cout << odd << "\n";
	else cout << even << "\n";
}
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
 
	int t;
	cin >> t;
	while (t--) {
		StretfordEnd();
	}
 
	return 0;
}