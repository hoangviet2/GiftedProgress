#include <bits/stdc++.h>
using namespace std;

vector<int> A;
vector<int> longestIncDown, longestDecUp;
vector<int> choiceInc, choiceDec;

int main() {
	int n; cin >> n; A.resize(n);
	for (int i = 0; i < n; i++) cin >> A[i];
	longestIncDown = longestDecUp = vector<int>(n, 1);
	choiceInc = choiceDec = vector<int>(n, -1);

	for (int i = 0; i < n; i++)
		for (int j = i - 1; j >= 0; j--)
			if (A[j] < A[i] && longestIncDown[i] < 1 + longestIncDown[j])
				longestIncDown[i] = 1 + longestIncDown[j],
				choiceInc[i] = j;

	for (int i = n-1; i >= 0; i--)
		for (int j = i+1; j < n; j++)
			if (A[i] > A[j] && longestDecUp[i] < 1 + longestDecUp[j])
				longestDecUp[i] = 1 + longestDecUp[j],
				choiceDec[i] = j;

	int res = 1, howToRes = 0;
	for (int i = 0; i < n; i++)
		if (res < longestIncDown[i] + longestDecUp[i] - 1)
			res = longestIncDown[i] + longestDecUp[i] - 1,
			howToRes = i;

	deque<int> resArr;
	int p = howToRes;
	for (; choiceInc[p] != -1; p = choiceInc[p])
		resArr.push_front(A[p]);
	resArr.push_front(A[p]);

	p = choiceDec[howToRes];
	if (p != -1) {
		for (; p != -1 && choiceDec[p] != -1; p = choiceDec[p])
			resArr.push_back(A[p]);
		resArr.push_back(A[p]);
	}

	for (auto XXX : resArr) cout << XXX << ' ';
}
