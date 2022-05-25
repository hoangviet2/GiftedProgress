#include <bits/stdc++.h>

using namespace std;

struct pairHash
{
	size_t operator()(const pair<int,int>& a) const
	{
		size_t seed = hash<int>{}(a.first);
		seed ^= hash<int>{}(a.second) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
		return seed;
	}
};

vector<int> arr;
unordered_map<pair<int, int>, int, pairHash> dp;

int dfs(int p, int curGCD)
{
	if (p == arr.size())
        return curGCD;
	if (dp.find({ p, curGCD }) != dp.end())
        return dp[{p, curGCD}];
	int res1 = -99, res2 = -99, res3 = -99;
	if (arr[p] - 1 > 0)
        res1 = dfs(p + 1, __gcd(curGCD, arr[p] - 1));
    res2 = dfs(p + 1, __gcd(curGCD, arr[p]));
    res3 = dfs(p + 1, __gcd(curGCD, arr[p] + 1));
	return dp[{p, curGCD}] = max({ res1, res2, res3 });
}

int main()
{
    freopen("GCDMAX.INP", "r", stdin);
	freopen("GCDMAX.OUT", "w", stdout);
	int n;
	cin >> n;
	arr.resize(n);
	for (int i = 0; i < n; i++) cin >> arr[i];
	cout << dfs(0, 0);
}