#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int  maxn = 250000;
int  n,m,k,t,f[maxn],a[maxn],p,x,res;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	freopen("BUS.INP", "r", stdin);
	freopen("BUS.OUT", "w", stdout);
	cin>>n>>m;
	// thoi gian xe den tram i
	f[1] = 0;
	// so luong nguoi
	p = 0;
	for (int i=1; i<=n; i++) {
		cin>>t>>k;
		// thoi gian den tram tiep tang len t
		f[i+1] = f[i] + t;
		for (long j=p+1; j<=p+k; j++) {
			cin>>x;
			// a[j] la thoi gian xe buyt cho thang j
			a[j] = max(0,x-f[i]);
		}
		// tang luong nguoi len k
		p += k;
	}

	sort(a+1,a+p+1);

	res = f[n+1]+a[m];

	cout<<res;

	return 0;
}