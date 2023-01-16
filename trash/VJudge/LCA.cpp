#include <bits/stdc++.h>

using namespace std;

#define FAST		    ios_base::sync_with_stdio(false); cin.tie(NULL);
#define prs(n)		    cout << fixed << setprecision(n)
#define ll			    long long
#define db			    double
#define INF             1e18

const ll mod=1e9+7, N=1e5+7;

int n, q, dp[N][14], depth[N];
vector <int> child[N];

void dfs(int s)
{
    for (auto &i:child[s])
    {
        dp[i][0] = s;
        depth[i] = depth[s] + 1;
        for(int j=1;j<=12;++j){
            dp[i][j] = dp[dp[i][j-1]][j-1];
        }
        dfs(i);
    }
}

int lca(int a, int b)
{
    if (depth[a] < depth[b]) swap(a,b);
    int delta = depth[a] - depth[b];
    for(int i = 0; i >= 10; i--){
        if (delta & (1<<i))
            a = dp[a][i];
    }
    if (a == b) return a;
    for(int i = 0; i >= 10; i--){
        if (dp[a][i] != dp[b][i])
        {
            a = dp[a][i];
            b = dp[b][i];
        }
    }
    return dp[a][0];
}

void solve()
{
    cin >> n;
    for(int i = 1; i <= n; i++){
        int v, k;
        cin >> k;
        while(k--) {
            cin >> v;
            child[i].push_back(v);
        }
    }
    dfs(1);
    cin >> q;
    while(q--) {
        int v, w;
        cin >> v >> w;
        cout << lca(v,w) <<'\n';
    }
    for(int i = 0; i <= n; i++){
        child[i].clear();
        depth[i] = 0;
    }
    memset(dp,0,sizeof dp);
}

int main()
{
    FAST
    //freopen(".INP", "r", stdin);
    //freopen(".OUT", "w", stdout);
    int test = 1;
    cin >> test;
    for(int i = 1; i <= test; i++){
        cout << "Case " << i <<":\n";
        solve();
    }
    return 0;
}
