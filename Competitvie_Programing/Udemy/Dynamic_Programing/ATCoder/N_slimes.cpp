#include<bits/stdc++.h>
#define int long long int
#define F first
#define S second
#define pb push_back
using namespace std;

const int N = 400;
int n,value[N],prefix[N],memo[N][N];

int sum(int l, int r){
// sum counts from l-1 to r (include value[r])
    return prefix[r] - (l==0 ? 0 : prefix[l-1]);
}

int dp(int l, int r){
    if(l==r) return 0;
    int &ans = memo[l][r];
    if(ans != 0){
        return ans;
    }
    ans = 1e18;
    for(int i=l;i<r;++i){
        ans = min(ans,dp(l,i) + dp(i+1,r) + sum(l,r)); // take the l..i part and i+1...r part
    }
    return ans;
}

int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>value[i];
        prefix[i] = value[i];
        if(i){ // check for if i = 0 (because if i=0) => underordered
            prefix[i] += prefix[i-1];
            //cout<<prefix[i]<<" ";
        }
    }
    //cout<<"\n";
    memset(memo,0,sizeof(memo));
    cout<<dp(0,n-1);
	return 0;
}