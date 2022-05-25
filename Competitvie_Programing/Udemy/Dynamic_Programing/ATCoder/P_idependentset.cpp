// https://atcoder.jp/contests/dp/tasks/dp_p
#include<bits/stdc++.h>
#define int long long int
#define F first
#define S second
#define pb push_back
using namespace std;

const int N = 1e5+1, mod = 1e9+7;
vector<int> gr[N];
int memo[N][2];
int dp(int curent,int paint, int pairing){
	int &ans = memo[curent][paint];
	if(ans != -1){
		return ans;
	}
	ans = 1;
	for(auto child:gr[curent]){
		if(child!=pairing){
			if(paint){
				ans *= dp(child,0,curent) + dp(child,1,curent);
			}else{
				ans *= dp(child,1,curent);
			}
			ans %= mod;
		}
	}

	return ans;
}

int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin>>n;
	for(int i=0;i<n-1;++i){
		int a,b;
		cin>>a>>b;
		gr[a].push_back(b);
		gr[b].push_back(a);
	}
	memset(memo,-1,sizeof(memo));
	cout<<(dp(1,1,0) + dp(1,0,0)) %mod;
	return 0;
}