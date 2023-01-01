#include <bits/stdc++.h>
#include <random>
#define ALL(v) (v).begin(),(v).end()
#define between(l,x,r) ((l) <= (x) && (x) <= (r))
#define len(s) ((i64)(s).size())
#pragma warning(disable:4996)
using namespace std;
using i64 = long long;
using ld = long double;
using vi = vector<i64>;
using pi = pair<i64,i64>;
using t3 = tuple<int,int,int>;

const i64 M = 1e9+7;
 
inline i64 modSub(i64 A, i64 B) {
	A %= M, B %= M  
	i64 res = (A-B)%M;
	res = (res+M) % M;
	return res;
}

inline i64 modAdd(i64 A, i64 B) {
	A %= M, B %= M;
	i64 res = (A+B) % M;
	return res;
}

inline i64 sumIntBetween(i64 L, i64 R) {
	if (L == 0) {
		return ((R*(R+1))/2) % M;
	}
	return modSub(sumIntBetween(0,R), sumIntBetween(0,L-1));
}

inline i64 evalPref(const vector<i64>& P, int L, int R) {
	if (L <= 0) return P[R];
	i64 res = (P[R] - P[L-1]) % M;
	res = (res + M) % M;
	return res;
}

inline void solve() {
	string S; cin >> S;
	int N = S.size();
	vector<i64> P[26], Pp[26];
	for (char c = 'a'; c <= 'z'; c++) {
		P[c-'a'].resize(N);
		Pp[c-'a'].resize(N);
		P[c-'a'][0] = Pp[c-'a'][0] = (S[0] == c);
		for (int i = 1; i < N; i++) {
			P[c-'a'][i] = P[c-'a'][i-1] + (S[i] == c);
			Pp[c-'a'][i] = Pp[c-'a'][i-1] + P[c-'a'][i];
		}
	}
	vector<i64> Gp[26];
	for (char c = 'a'; c <= 'z'; c++) {
		Gp[c-'a'].resize(N);
		Gp[c-'a'][0] = P[c-'a'][0]*0;
		for (int i = 1; i < N; i++) {
			Gp[c-'a'][i] = Gp[c-'a'][i-1] + ((P[c-'a'][i]*i) % M);
			Gp[c-'a'][i] %= M;
		}
	}

	i64 contr[26]; memset(contr, 0, sizeof(contr));
	i64 ADDER = -1;
	for (char c = 'a'; c <= 'z'; c++) {
		for (i64 i = 0; i < N; i++) {
			//contr[c-'a'] += evalPref(Gp[c-'a'], i, N - 1);
			contr[c-'a'] = modAdd(contr[c-'a'], evalPref(Gp[c-'a'], i, N - 1));

			if (i > 0) {
				ADDER = P[c-'a'][i-1LL]; // * (i-1LL) * (N-i);
				ADDER = (ADDER * (i-1LL)) % M;
				ADDER = (ADDER * (N-i)) % M;
				contr[c-'a'] = (contr[c-'a'] + ADDER) % M;
			}

			ADDER = (i-1LL) % M;
			ADDER = (ADDER * evalPref(Pp[c-'a'], i, N-1)) % M;
			contr[c-'a'] = modSub(contr[c-'a'], ADDER) % M;
			//contr[c-'a'] -= (i-1LL) * evalPref(Pp[c-'a'], i, N-1);

			if (i > 0) {
				ADDER = (P[c-'a'][i-1]) % M;
				ADDER = (ADDER * sumIntBetween(i, N-1));
				contr[c-'a'] = modSub(contr[c-'a'], ADDER);
				//contr[c-'a'] -= P[c-'a'][i-1] * sumIntBetween(i, N-1);
			}
		}
	}
	
	i64 res = 0;
	for (char c = 'a'; c <= 'z'; c++) {
		ADDER = (contr[c-'a'] * (c-'a'+1LL)) % M;
		res = (res + ADDER) % M;
	}
	cout << res;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T; cin >> T;
	while (T--) {
		solve();
		cout << '\n';
	}
}