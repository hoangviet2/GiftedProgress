// D
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxN = 1e5+7;
vector<int> values;
int ans[maxN], n, queries;
struct Point
{
	static Point pool[maxN * 40], *ptr;
	static const Point HOLE;
	int sum;
	const Point *lc, *rc;
	Point(): sum(0), lc(&HOLE), rc(&HOLE) {}
	Point(int _s, const Point *l, const Point *r): sum(_s), lc(l), rc(r) {}
	Point *insert(int p, int l=1, int r=n) const
	{
		if (l==r) return new(ptr++) Point{sum+1, lc, rc};
		int m=(l + r)>>1;
		Point *n=new(ptr++) Point{sum+1, lc, rc};
		if (p<=m)
        {
			if(!n->lc)
                n->lc=Point().insert(p, l, m);
			else
                n->lc=n->lc->insert(p, l, m);
		}
		else
		{
			if(!n->rc)
                n->rc=Point().insert(p, m+1, r);
			else
                n->rc=n->rc->insert(p, m+1, r);
		}
		return n;
	}
	int query(const Point *old, int k, int l=1, int r=n) const{
		if (l==r)
            return l;
		int lSum=lc->sum-old->lc->sum;
		int m=(l+r)>>1;
		if(k<=lSum)
            return lc->query(old->lc, k, l, m);
		else
            return rc->query(old->rc, k-lSum, m+1, r);
	}
} *root[maxN], Point::pool[maxN * 40], *Point::ptr;
const Point Point::HOLE = Point(0, &Point::HOLE, &Point::HOLE);

void solve(){
    cin>>n>>queries;
    Point init=Point();
	root[0]=&init;
    Point::ptr=Point::pool;
    for(int i=1; i<=n; i++){
        cin>>ans[i];
        values.push_back(ans[i]);
    }
    sort(values.begin(), values.end());
    values.resize(unique(values.begin(), values.end())-values.begin());
    for(int i=1; i<=n; i++){
        ans[i]=lower_bound(values.begin(), values.end(), ans[i])-values.begin()+1;
        root[i]=root[i-1]->insert(ans[i]);
    }
    while(queries--){
        int l, r, k;
        cin>>l>>r;
        k=((l+r)/2)-l+1;
        cout<<values[root[r]->query(root[l-1], k)-1]<<'\n';
    }
}

int main(){
#ifndef ONLINE_JUDGE

    freopen("input.txt", "r", stdin);

    freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);
    int t = 1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
