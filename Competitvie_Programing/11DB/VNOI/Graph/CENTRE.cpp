#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<int> vi;
typedef vector<vi> vvi;

#define sz(a) int((a).size())
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(), (c).end()
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(), _e = (c).end(); i != _e; ++i)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define rep(i,n) for(int i = 0, _n = (n); i < _n; ++i)
#define repd(i,n) for(int i = (n)-1; i >= 0; --i )
#define fo(i,a,b) for(int i = (a), _b = (b); i <= _b; ++i)
#define fod(i,a,b) for(int i = (a), _b = (b); i >= _b; --i)

#define INF 1000000000
#define N 30005
typedef long long LL;

int d1[N], d2[N], n, m;
LL c1[N], c2[N];
vvii g;

void dijkstra(vvii&g, int s, int *d, LL *c) {
    fill(d,d+n,INF); d[s] = 0; c[s] = 1;
    priority_queue< ii, vii, greater<ii> > qu;
    qu.push(ii(0,s));
    while(!qu.empty()) {
        int u = qu.top().se, du = qu.top().fi; qu.pop();
        if(du > d[u]) continue;
        tr(g[u],it) {
            int v = it->fi, l = it->se;
            if( du + l < d[v] ) {
                qu.push(ii(d[v] = du+l,v));
                c[v] = c[u];
            } else if( du + l == d[v] ) c[v] += c[u];
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen( "input.txt", "r", stdin );
    freopen( "output.txt", "w", stdout );
#endif
    scanf("%d%d",&n,&m); g.resize(n);
	for(int i = 0;i<m;++i){
		int u,v,l;
		cin>>u>>v>>l;
		g[--u].push_back(make_pair(--v,l));
		g[v]
	}
    rep(i,m) {
        int u, v, l; scanf("%d%d%d",&u,&v,&l);
        g[--u].pb(ii(--v,l)); g[v].pb(ii(u,l));
    }
    dijkstra(g, 0, d1, c1);
    dijkstra(g, n-1, d2, c2);
    vi res;
    rep(i,n)
        if(!(d1[i]+d2[i]==d1[n-1] && c1[i]*c2[i]==c1[n-1])) res.pb(i+1);
    printf("%d\n",sz(res));
    tr(res,it) printf("%d\n",*it);
    return 0;
}
