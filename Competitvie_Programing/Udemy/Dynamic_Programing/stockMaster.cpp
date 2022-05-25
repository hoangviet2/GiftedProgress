#include <iostream>
#include <vector>
using namespace std;
int maxProfit(int k, vector<int> prices) {
    int n = prices.size();
    if(n==0){
        return 0;
    }
    vector<vector<int> > dp(k+1,vector<int>(n+1,0));
    // x: k+1 (transaction)
    // y: prices of stock
    // note: using 2D array DP when the answer depending on more than 2 aspect
    for(int i=1;i<=k;++i){
        for(int j=1;j<n;++j){
            dp[i][j] = dp[i][j-1];
            for(int z=0;z<j;++z){
                dp[i][j] = max(dp[i][j],prices[j]-prices[z]+dp[i-1][z]);
            }
        }
    }
    return dp[k][n-1];
}
int main(){
    //cout<<maxProfit(2, vector<int> {2,4,1} );
    return 0;
}