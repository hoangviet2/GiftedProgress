#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;

const int N = 2e5 + 8;
int n, p[N];
char c[N];

ll gcd(ll a, ll b) {
    if (a == 0){
        return b;
    }
    return gcd(b % a, a);
}
ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

bool mark[N];
int kmp[N];
ll calc(int x) {
    string s("");
    for (int i = x; !mark[i]; i = p[i]) {
        mark[i] = true;
        s += c[i];
    }
    int len = s.size();
    s += s;

    kmp[0] = 0;
    for (int i = 1, j = 0; i < s.size(); ++i) {
        while (j && s[i] != s[j]) j = kmp[j - 1];
        if (s[i] == s[j]) ++j;
        kmp[i] = j;
    }
    for (int i = len; i < s.size(); ++i)
        if (kmp[i] == len) return i - len + 1;
    return len;
}

ll solve() {
    cin >> n >> (c + 1);
    for (int i = 1; i <= n; ++i) cin >> p[i];

    fill(mark + 1, mark + n + 1, false);
    ll ans(1);
    for (int i = 1; i <= n; ++i){
        if (!mark[i]){
            ans = lcm(ans, calc(i));
        {
    }
    cout<<ans<<"\n";
}

int main() {
    cin.tie(NULL)->sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
