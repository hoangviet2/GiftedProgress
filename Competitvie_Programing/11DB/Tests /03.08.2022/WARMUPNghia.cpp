#include <bits/stdc++.h>
using namespace std;
typedef long long i64;

// return pow(base, exp) mod M
i64 modPow(i64 base, i64 exp, const i64& M) {
	base %= M;
	if (exp == 0) return 1LL % M;
	if (exp % 2 == 1) return (base * modPow(base, exp-1, M)) % M;
	i64 toSq = modPow(base, exp/2, M);
	return (toSq*toSq) % M;
}

// return (a-b) mod M
i64 modSub(i64 a, i64 b, const i64& M) {
	a %= M; b %= M;
	i64 res = (a-b) % M;
	while (res < 0) res += M;
	return res;
}

// return (a*b) mod M
i64 modMul(i64 a, i64 b, const i64& M) {
	a %= M; b %= M;
	return (a*b) % M;
}

// return (a+b) mod M
i64 modAdd(i64 a, i64 b, const i64& M) {
	a %= M; b %= M;
	return (a+b) % M;
}

// T(k) mod p with a given a
i64 T(i64 a, i64 k, i64 p) {
	i64 curAPow = 1;
	i64 curExp = 0;
	i64 res = 0;
	while (curExp <= k) {
		res = modAdd(res, curAPow, p);
		curAPow = modMul(curAPow, a, p);
		curExp++;
	}
	return res;
}

i64 BF(i64 n, i64 a, i64 p) {
	i64 res = 0;
	for (i64 i = 0; i <= n; i++) {
		res = modAdd(res, T(a, i, p), p);
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
#ifndef ONLINE_JUDGE

    freopen("input.txt", "r", stdin);

    freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
	i64 n, a, p; cin >> a >> n >> p;
	if (n <= 3000) {
		cout << BF(n, a, p);
		return 0;
	}
	i64 res = 0;
	
	if (a == 1) {
		res = modMul(n, n+1, p);
		res = modMul(res, modPow(2, p-2, p), p);
		res = modAdd(res, n, p);
		cout << res;
		return 0;
	}

	// now use some geometric sum magickery

	i64 theInversedGuy = modPow(a-1, p-2, p);
	res = modPow(a, n+2, p);
	res = modSub(res, 1, p);
	res = modMul(res, theInversedGuy, p);
	res = modSub(res, n+2, p);
	res = modMul(res, theInversedGuy, p);
	cout << res;
}
