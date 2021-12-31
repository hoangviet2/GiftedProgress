#include <bits/stdc++.h>

using namespace std;

#define fo(i,m,n) for(int i = m; i <= n; i++)
#define fod(i,m,n) for(int i = m; i >= n; i--)
#define fov(i,x) for(auto &i : x)
#define cyes cout <<  "YES" << '\n';
#define cno cout << "NO" << '\n';

typedef long long ll;
typedef int64_t i64;
typedef long double ld;
typedef pair<int,int> _ii;
typedef vector<_ii> vii;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    ll n,m;
    cin >> n >> m;
    vector < pair<ld,ld> > v;
    fo(i,0,n-1)
    {
        ll a,b;
        cin >> a >> b;
        v.push_back({a,b});
    }
    ld x = 0;
    fo(i,0,n-1)
        x += (v[i].first - (v[i].first/(v[i].second+1)));
    ld s;
    s = m/x;
    fo(i,0,n-1)
        s -=  x*(1/v[i].second);
    cout << ceil(s);
}