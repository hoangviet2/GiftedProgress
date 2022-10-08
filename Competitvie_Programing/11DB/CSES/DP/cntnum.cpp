#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll countNoSameAdjacentNumbers(ll num, vector<ll> &dp) {
    if (num < 1)
        return num == 0 ? 1 : 0;
    string numString = to_string(num);
    ll res = 0;
    for (int i = 0; i < numString.size(); i++) {
        res += dp[i];
    }
 
    int prev = 0;
    for (int i = 0; i < numString.size(); i++) {
        int digit = numString[i] - '0';
        int diff = numString.size() - i - 1;
        int below = prev < digit ? digit - 1 : digit;
        res += (digit == 0) ? 0 : below * dp[diff];
        if (digit == prev)
            return res;
        prev = digit;
    }
    return res + 1;
}
 
int main() {
    ll a, b;
    cin >> a >> b;
    vector<ll> dp(19);
    dp[0] = 1;
    ll res = 1;
    for (int i = 1; i < 19; i++) {
        res *= 9;
        dp[i] = res;
    }
    cout << (countNoSameAdjacentNumbers(b, dp) - countNoSameAdjacentNumbers(a-1, dp));
 
    return 0;
}