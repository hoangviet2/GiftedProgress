#include<bits/stdc++.h>
#include <vector>
#include <iostream>
#include <iomanip>
#define int long long int
#define F first
#define S second
#define pb push_back
using namespace std;
double arr[3000], memo[3000][3000];
int n;
double dp(int i,int head,int tail){
	if(i==n){
		return 1.00;
	}
	double &ans = memo[i][head];
	if(ans != -1.00) return ans;
	ans = 0.00;
	if(head){
		ans += dp(i+1,head-1,tail)*arr[i];
	} 
	if(tail){
		ans += dp(i+1,head,tail-1)*(1.00-arr[i]);
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
		cin>>arr[i];
	}

	for(int i=0;i<3000;++i){
		for(int j=0;j<3000;++j){
			memo[i][j] = -1.00;
		}
	}

	double ans = 0;
	cout<<setprecision(10)<<fixed;
	for(int i= (n/2+1);i<=n;++i){
		ans += dp(0,i,n-i);
	}
	cout<<ans;
	return 0;
}