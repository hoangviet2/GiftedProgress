#include <bits/stdc++.h>
#define F(i, a) for (int i = 0; i < a; i++)
#define FO(i, a, b) for(int i = a; i <= b; i++)
#define f first
#define s second
#define endl "\n"

using namespace std;

void input() {
    freopen("Phone.inp", "r", stdin);
    freopen("Phone.out", "w", stdout);
}

typedef long long ll;
typedef pair<int, int> ii;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    input();
    ll n, m, a, b, sum = 0, prev = 0;
    set<ii> s;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        s.insert({a, b});
    }
    for (auto it = s.begin(); it != s.end(); ++it) {
        if ((*it).s > prev) {
            sum = sum + ((*it).s - prev);
        }
        prev = (*it).s;
    }
    cout << sum;
}
