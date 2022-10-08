#include <bits/stdc++.h>

using namespace std;

int N, M;
int check(vector<vector<int>>& G) {
	int res = 0;
	for (int i = 0; i < M; i++) {
		if (G[0][i] == 1) {
			res++;
			for (int j = 0; j < N; j++)
				G[j][i] = 1 - G[j][i];
		}
	}
	for (int i = 0; i < N; i++) {
		bool fullOne = true, fullZero = true;
		for (int j = 0; j < M; j++)
			fullOne &= G[i][j] == 1,
			fullZero &= G[i][j] == 0;
		if (fullOne) res++;
		else if (!fullOne && !fullZero)
			return 1e9;
	}
}

int main() {
	cin >> N >> M;
	vector<string> G1(N), G2(N);
	vector<vector<int>> G(N, vector<int>(M));
	for (int i = 0; i < N; i++)
		cin >> G1[i];
	for (int i = 0; i < N; i++)
		cin >> G2[i];
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			G[i][j] = ((G2[i][j]-'0') - (G1[i][j]-'0') + 2) % 2;
	vector<vector<int>> GCopy = G;
	// Case 1: press first row
	for (int i = 0; i < M; i++)
		GCopy[0][i] = 1 - GCopy[0][i];
	int res1 = 1 + check(GCopy);
	// Case 2: dont press first row
	int res2 = check(G);
	cout << (min(res1, res2) >= 1e9 ? -1 : min(res1, res2));
}