#include<bits/stdc++.h>
#define int long long int
#define F first
#define S second
#define pb push_back

using namespace std;
const int mod = 1e9+7;
int n,m;
vector<vector<char>> grid;

int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    cin>>n>>m;
    for(int i=0;i<n;++i){
        vector<char> line;
        for(int j=0;j<m;++j){
            char x;
            cin>>x;
            line.push_back(x);
        }
        grid.push_back(line);
    }

    int dp[n][m];
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(i==0 && j==0){
                dp[i][j] = 1;
            }
            else if(i==0){
                dp[i][j] = dp[i][j-1];
            }
            else if(j==0){
                dp[i][j] = dp[i-1][j];
            }else{
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
            if(grid[i][j] == '#'){
                dp[i][j] = 0;
            }
        }
    }
    cout<<dp[n-1][m-1];
	return 0;
}