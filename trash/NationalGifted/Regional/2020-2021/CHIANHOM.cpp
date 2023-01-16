#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define FAST            ios_base::sync_with_stdio(false); cin.tie(NULL);
#define prs(n)          cout << fixed << setprecision(n)
#define ll              long long
#define db              double
#define fo(i,m,n)       for(int i = m; i <= n; i++)
#define fob(i,m,n)      for(int i = n; i >= m; i--)
typedef                 pair<int, int> ii;
typedef                 vector<ii> vii;
typedef                 vector<vii> vvii;
typedef                 tree<int, null_type, less_equal<long long>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
const                   int _x[] = {-1, 0, 1, 0};
const                   int _y[] = {0, 1, 0, -1};
const                   char _step[] = {'U','R','D','L'};

const ll mod=1e9+7, N=2e6 + 7;

ll f[N][10], a[N], n, q, L, R, x;

void solve()
{
    cin >> n >> q;
    fo(i,1,n) {
        cin >> x;
        fo(j,0,9)
            f[i][j] = f[i-1][j];
        f[i][x%10]++;
    }
    while(q--) {
        cin >> L >> R;
        fo(j,0,9) {
            cout << f[R][j]-f[L-1][j] <<' ';
        }
        cout << '\n';
    }
}

int main()
{
    FAST
    freopen("CHIANHOM.INP", "r", stdin);
    freopen("CHIANHOM.OUT", "w", stdout);
        solve();
    return 0;
}
