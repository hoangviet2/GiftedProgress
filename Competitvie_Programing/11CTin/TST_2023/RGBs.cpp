#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ed '\n'

const ll maxn = 2*1e3+1;

ll n, c[maxn];
ll a[maxn][maxn];
ll b[maxn][maxn];
bool dd[maxn][maxn];
void read_data()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> c[i];
    for (int i = 1; i < n; i++){
        ll x,y,cost;
        cin >> x >> y >> cost;
        a[x][y] = cost;
        a[y][x] = cost;
    }
}
void dq(ll point, ll id, ll cost)
{
    for (int i = 1; i <= n; i++)
    {
        if (a[id][i] != 0 && dd[id][i] == true)
        {
            b[point][i] = min(b[point][i], cost + a[id][i] + c[i]);
            dd[id][i] = false; dd[i][id] = false;
            dq(point, i, cost + a[id][i]);
            dd[id][i] = true; dd[i][id] = true;
        }
    }
}
void sol()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            dd[i][j] = true;
            b[i][j] = LONG_LONG_MAX;
        }
        b[i][i] = 0;
    }

    for (int i = 1; i <= n; i++)
    {
        dq(i,i,0);
    }
    for (int i = 1; i <= n; i++)
    {
        ll Max = LONG_LONG_MIN;
        for (int j = 1; j <= n; j++)
        {
            Max = max(Max, b[i][j]);
        }
        cout << Max << " ";
    }
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("RGB.INP" ,"r" ,stdin);
    freopen("RGB.OUT" ,"w" ,stdout);
    read_data();
    sol();
    return 0;
}
