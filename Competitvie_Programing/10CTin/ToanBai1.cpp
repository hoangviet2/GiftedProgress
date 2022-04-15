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
    ld a,b,c;
    cin>>a>>b>>c;
    cout<<setprecision(10)<<fixed;
    ld p = (a+b+c)/2.000;
    ld herong = sqrt(p * (p-a)*(p-b)*(p-c));
    cout<<(a*b*c)/(herong*4)<<"\n";
    cout<<((a*b*c)/(herong*4))*2;
	return 0;
}