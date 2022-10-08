#include <bits/stdc++.h>
using namespace std;
const int N = 6105;
int dp[N][N];
int main(){
// #ifndef ONLINE_JUDGE

//     freopen("input.txt", "r", stdin);

//     freopen("output.txt", "w", stdout);

// #endif // ONLINE_JUDGE
	int testcase;
    cin>>testcase;
    while(testcase--){
        string s;
        cin>>s;
        int n = s.size();
        memset(dp,0,sizeof(dp));
        for(int i=n-2;i>=0;--i){
            for(int j=i+1;j<n;++j){
                if(s[i] == s[j]){
                    dp[i][j] = dp[i+1][j-1];
                }else{
                    dp[i][j] = min(dp[i+1][j],dp[i][j-1]) +1;
                }
            }
        }
        cout<<dp[0][n-1]<<'\n';
    }
	return 0;
}
