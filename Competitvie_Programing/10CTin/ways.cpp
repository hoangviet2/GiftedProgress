// Bài 1 LMH
#include <iostream>
#include <vector>

using namespace std;
int solve(int n){
    vector<vector<int>> dp(n+1,vector<int> (n+1,0));
    for(int i=0;i<n;++i){
        dp[i][0] = 1;
    }
    dp[0][0] = 1;
    for(int i=1;i<=n;++i){// i là m
        for(int j=0;j<=n;++j){ // j là v
            if(j<i){
                dp[i][j] = dp[i-1][j]; // TH1
            }else{
                dp[i][j] = dp[i-1][j] + dp[i][j-i];// TH2
            }
        }
    }
    return dp[n][n];
}
int main(){
    int temp;
    cin>>temp;
    cout<<solve(temp);
    return 0;
}