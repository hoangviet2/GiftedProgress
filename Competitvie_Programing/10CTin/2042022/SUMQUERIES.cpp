#include<bits/stdc++.h>
#define int long long int
#define F first
#define S second
#define pb push_back
using namespace std;
const int N = 1e5+1;
int a[N],dp[N];
int n,q;
int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("SUMQUERIES.INP", "r", stdin);
	freopen("SUMQUERIES.OUT", "w", stdout);
#endif
    cin>>n>>q;
    int sum = 0;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        sum+=a[i];
        dp[i] = sum;
    }
    for(int i=0;i<q;++i){
        int start,end;
        cin>>start>>end;
        cout<<dp[end] - dp[start-1]<<"\n";
    }
	return 0;
}