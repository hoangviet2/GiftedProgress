#include <iostream>
#include <vector>
#include <utility>
using namespace std;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<pair<pair<int, int>, int>> ans;
    for (int i = 0; i < n; ++i) {
        int posmin = i;
        for (int j = i + 1; j < n; ++j) {
            if (a[j] < a[posmin]) posmin = j;
        }
        if (posmin > i) {
            ans.push_back({ {i, posmin}, posmin - i });
            for (int k = posmin; k > i; --k) {
                a[k] = a[k - 1];
            }
        }
    }
    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i].first.first + 1 << " " << ans[i].first.second + 1 << " " << ans[i].second << "\n";
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
}
