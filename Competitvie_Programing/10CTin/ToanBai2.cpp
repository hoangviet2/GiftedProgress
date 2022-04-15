#include<bits/stdc++.h>
#define int long long int
#define ld long double
#define F first
#define S second
#define pb push_back
using namespace std;

int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    ld minAlpha,maxAlpha,distance,height;
    cin>>minAlpha>>maxAlpha>>distance>>height;
    minAlpha = minAlpha*M_PI/180;
    maxAlpha = maxAlpha*M_PI/180;
    cout<<setprecision(10)<<fixed;
    cout<<( distance/ ( (1/tan(minAlpha)) - (1/tan(maxAlpha)) ) )+height;
	return 0;
}