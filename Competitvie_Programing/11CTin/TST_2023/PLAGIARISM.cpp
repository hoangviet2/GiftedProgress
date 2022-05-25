// bài 1
#include<bits/stdc++.h>
#define int long long int
using namespace std;
const int N = 10000;
string s,t;
int n,m,memo[N][N];

int give_lcs(int i,int j){
	if(i==n || j==m) return 0;
	int &ans = memo[i][j];

	if(ans!=-1) return ans;

	if(s[i] == t[j]){
		ans = give_lcs(i+1,j+1) + 1;
	}else{
		ans = 0;
	}
	return ans; 
}


int32_t main(){
#ifndef ONLINE_JUDGE
	freopen("PLAGIARISM.INP", "r", stdin);
	freopen("PLAGIARISM.OUT", "w", stdout);
#endif
    cin>>n>>m;
    cin>>s>>t;
	n = s.length();
	m = t.length();
	memset(memo,-1,sizeof(memo));
	int l = give_lcs(0,0);
	cout<<l;
	return 0;
}