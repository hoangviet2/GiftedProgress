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

int n, m, ans;
vector <int> a[N];
bool vis[N];

void dfs(int s)
{
    vis[s] = true;
    for (auto &i:a[s])
        if (!vis[i]) dfs(i);
}

void solve()
{
    bool flag = true;
    cin >> n >> m;
    fo(i,1,m)
    {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
        if (i < n-1 || flag == false) continue;
        int cnt = 0;
        fo(j,0,n-1) vis[j] = false;
        fo(j,0,n-1)
        {
            if (!vis[j]) {
                cnt++;
                dfs(j);
            }
        }
        if (cnt == 1) {
            cout << i;
            flag = false;
        }
    }
}

int main()
{
    FAST
    freopen("LAMDUONG.INP", "r", stdin);
    freopen("LAMDUONG.OUT", "w", stdout);
        solve();
    return 0;
}
