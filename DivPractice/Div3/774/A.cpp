#include <iostream>
#include <string>
using namespace std;
void solve() {
    string s;
    cin >> s;
    int cnta = 0;
    int cntb = 0;
    int cntc = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == 'A') ++cnta;
        if (s[i] == 'B') ++cntb;
        if (s[i] == 'C') ++cntc;
    }
    if (cnta + cntc == cntb) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}