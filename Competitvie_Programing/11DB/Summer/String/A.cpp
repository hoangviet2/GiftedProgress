#include <bits/stdc++.h>
using namespace std;

void slove(){
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int cnt = 0;
    int first = n;
    int last = -1;
    for (int p = 0; p < n; p++) {
        if (s[p] != '1'){
            continue;
        }
        cnt += 1;
        if (first == n){
            first = p;
        }
        last = p;
    }
    int add = 0;
    //  cost đưa số 1 lên cuối dãy
    if (cnt > 0 && (n - 1 - last) <= k) {
        k -= (n - 1 - last);
        add += 1;
        cnt -= 1;
    }
    // cost đưa số 1 về đầu dãy
    if (cnt > 0 && first <= k) {
        k -= (first);
        add += 10;
        cnt -= 1;
    }
    // 10 + 11*ones + 1;
    cout << 11 * cnt + add << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE

    //freopen("input.txt", "r", stdin);

    freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
    int t;
    cin >> t;
    while (t--) {
        slove();
    }
  return 0;
}