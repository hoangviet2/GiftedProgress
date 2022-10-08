#include<bits/stdc++.h>
#define int long long int
using namespace std;
const int N = 3000;
string s,t,res;
int n,m,memo[N][N];

int give_lcs(int i,int j){
	if(i==n || j==m) return 0;
	int &ans = memo[i][j];

	if(ans!=-1) return ans;

	if(s[i] == t[j]){
		ans = give_lcs(i+1,j+1) + 1;
	}else{
		ans = max(give_lcs(i+1,j),give_lcs(i,j+1));
	}
	return ans; 
}

void trace(int i,int j){
	if(i==n || j==m) return;

	if(s[i] == t[j]){
		res += s[i];
		trace(i+1,j+1);
	}else{
		if(give_lcs(i+1,j) == give_lcs(i,j)){
			trace(i+1,j);
		}else{
			trace(i,j+1);
		}
	}
}

int32_t main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    cin>>s>>t;
	n = s.length();
	m = t.length();
	memset(memo,-1,sizeof(memo));
	//int l = give_lcs(0,0);
	//cout<<l;
	trace(0,0);
	cout<<res;
	return 0;
}