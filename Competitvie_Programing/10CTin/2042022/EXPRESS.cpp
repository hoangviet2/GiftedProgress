#include<bits/stdc++.h>


#define int long long int
#define F first
#define S second
#define pb push_back
using namespace std;

const int N = 1007;
int a[N],dp[N],n;

int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("EXPRESS.INP", "r", stdin);
	freopen("EXPRESS.OUT", "w", stdout);
#endif
    cin>>n;
    for(int i=1; i<=n; ++i){
        cin>>a[i];
        dp[i]= dp[i-1]+a[i];
    }

    // process
    int sum = 0, Max = 0;
    for(int i=1; i<n; ++i)
    {
        for(int j=i+1; j<n; ++j)
        {
            sum= a[i]*a[i+1]+a[j]*a[j+1]+dp[j-1]-dp[i+1]+dp[n]-dp[j+1];
            Max=max(Max, sum);
        }
    }
    cout<<Max<<"\n";
	return 0;
}