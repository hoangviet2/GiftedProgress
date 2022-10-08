#include <bits/stdc++.h>
#include <unordered_map>
#pragma warning(disable:4996)
#define ALL(v) v.begin(), v.end()
#define SEG(v, l, r) v.begin()+l, v.begin()+r+1
#define minSeg(v,l,r) *min_element(v.begin()+l,v.begin()+r+1)
#define maxSeg(v,l,r) *max_element(v.begin()+l,v.begin()+r+1)
#define MP(a,b) make_pair(a,b)
#define len(s) (i64)s.size()
using namespace std;
typedef long long i64;
typedef long double ld;
i64 popcount(i64 x) { i64 ans = 0; for (; x > 0; ans += x % 2 == 1, x /= 2); return ans; }
//string toBin(i64 x) { string ans = ""; for (; x > 0; ans += to_string(x % 2), x /= 2); reverse(ALL(ans)); return ans; }

i64 gcd(i64 a, i64 b) {
	if (b == 0) return a;
	return gcd(b, a%b);
}

i64 lcm(i64 a, i64 b) {
	return a / gcd(a, b) * b;
}

i64 mutiplesLessThanEqual(i64 x, i64 n) {
	return 1 + n / x;
}

void solve1(i64 n, i64 k) {
	vector<bool> cake(n);
	set<i64> A;
	for (i64 i = 0; i < k; i++) {
		i64 x; cin >> x;
		A.insert(x);
	}
	for (auto i : A)
		for (i64 j = 0; i*j < n; j++)
			cake[i*j] = true;
	cout << count(ALL(cake), false);
}

void solve2(i64 n, i64 k) {
	vector<i64> A(k);
	set<i64> As;
	for (i64 i = 0; i < k; i++) cin >> A[i];
	As = set<i64>(ALL(A));
	A = vector<i64>(ALL(As));
	map<i64, vector<i64>> chooseElements;
	for (i64 i = 1; i < (1 << len(A)); i++)
		chooseElements[popcount(i)].push_back(i);
	i64 res = 0;
	for (i64 i = 1; i <= k; i++) {
		i64 sign = i % 2 ? 1 : -1;
		for (auto choice : chooseElements[i]) {
			i64 LCM = 1;
			for (i64 j = 0; j < len(A); j++, choice /= 2)
				if (choice % 2) LCM = lcm(LCM, A[j]);
			res += mutiplesLessThanEqual(LCM, n-1)*sign;
		}
	}
	cout << n - res;
}

int main() {
	i64 n, k; cin >> n >> k;
	if (n <= 1e6) solve1(n, k);
	else solve2(n, k);
}