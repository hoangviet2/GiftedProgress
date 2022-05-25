#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> intervals;
vector<int> choice;
vector<int> dp;

// most money starting with p'th time
int helper(int p) {
	if (dp[p] != -1) return dp[p];
	int ans = intervals[p][2];
	for (int i = 0; i < intervals.size(); i++)
		if (i == p) continue;
		else if (intervals[p][1] <= intervals[i][0])
			ans = max(ans, intervals[p][2] + helper(i)),
			choice[p] = (ans == intervals[p][2] + helper(i) ? i : choice[p]);
	return dp[p] = ans;
}

int main() {
	int n; cin >> n;
	intervals = vector<vector<int>>(n, vector<int>(3));
	for (int i = 0; i < n; i++)
		cin >> intervals[i][0] >> intervals[i][1] >> intervals[i][2];
	dp = choice = vector<int>(n, -1);
	int res = 1, howToRes = 0;
	for (int i = 0; i < intervals.size(); i++)
		if (helper(i) > res)
			res = helper(i),
			howToRes = i;

	int p = howToRes;
	for (; choice[p] != -1; p = choice[p])
		cout << intervals[p][0] << ' ' << intervals[p][1] << '\n';
	cout << intervals[p][0] << ' ' << intervals[p][1];
}
