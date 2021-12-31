//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int64_t MOD = 1e9 + 7;
vector<vector<int>> dp;
vector<int> arr;
int arrSum = 0;
int bestDelta = -1;
void showArray(vector<vector<int>> dp){
    for(auto element:dp){
        for(auto elements:element){
            cout<<elements<<" ";
        }
        cout<<"\n";
    }
}
// find best delta
int minDelta(int p, int curSum) {
    cout<<"Current Sum: "<<curSum<<"\n";
    cout<<"Position: "<<p<<"\n";
    cout<<"Array Sum: "<<arrSum<<"\n";
    if (p >= arr.size()) {
        int remaining = arrSum - curSum;
        cout<<"Current Sum: "<<curSum<<"\n";
        cout<<"Array Sum: "<<arrSum<<"\n";
        cout<<"Remaining: "<<remaining<<"\n";
        return abs(remaining - curSum);
    }
    if (dp[p][curSum] != -1){
        cout<<"DP at: "<<p<<": "<<dp[p][curSum]<<"\n";
        return dp[p][curSum];
    }
    int ans = -1;
    // ignore this num
    ans = minDelta(p + 1, curSum);

    // take this num
    ans = min(ans, minDelta(p + 1, curSum + arr[p]));
    showArray(dp);
    return dp[p][curSum] = ans;
}

// how many ways to make delta
int countWays(int p, int curSum) {
    if (p >= arr.size()) {
        int remaining = arrSum - curSum;
        return abs(remaining - curSum) == bestDelta;
    }
    if (dp[p][curSum] != -1) return dp[p][curSum];
    int64_t ans = 0;
    // ignore this num
    ans = ((ans%MOD) + (countWays(p + 1, curSum)%MOD)) % MOD;

    // take this num
    ans = ((ans%MOD) + (countWays(p + 1, curSum + arr[p])%MOD)) % MOD;

    return dp[p][curSum] = ans;
}

int64_t modPow(int64_t base, int64_t exp, int64_t M) {
    if (exp == 0) return 1;
    int64_t ans = 1;
    if (exp % 2 == 0) {
        ans = modPow(base, exp / 2, M);
        ans = (ans * ans) % M;
    }
    else {
        ans = modPow(base, exp - 1, M);
        ans = (ans * (base % M)) % M;
    }
    return ans;
}

int main() {
    int n; cin >> n;
    arr.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        arrSum += arr[i];
    }

    dp = vector<vector<int>>(n, vector<int>(arrSum + 1, -1));
    bestDelta = minDelta(0, 0);

    // reset dp
    dp = vector<vector<int>>(n, vector<int>(arrSum + 1, -1));
    int64_t howManyWays = countWays(0, 0);

    // divide it by 2 bcuz overcounts: (a/2)%P
    // (a/b) % P <=> (a * b^(P-2)) % P idk why
    howManyWays = ((howManyWays)* modPow(2, MOD - 2, MOD)) % MOD;
    cout << bestDelta << ' ' << howManyWays;
}
