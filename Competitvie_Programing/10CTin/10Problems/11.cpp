#include<bits/stdc++.h>
#define int long long int
#define F first
#define S second
#define pb push_back

using namespace std;
const int N = 101;
int n;
int a[N][2];

bool comp(const vector<int>&a,const vector<int>&b){
    return a[1]<b[1];
}
int dp[N];
int dpFunc(){
    dp[0] = 1;
    int ans = 1;
    for(int i=1;i<n;++i){
        for(int j=0;j<i;++j){
            if(a[i][1]>=a[j][0]){
                dp[i] = max(dp[i]+1,dp[j]);
                ans = max(ans,dp[i]);
            }
        }
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
        cin>>a[i][0]>>a[i][1];
    }
    cout<<dpFunc();
	return 0;
}