#include <iostream>
#include <vector>
using namespace std;
int laddersTopDown(int n,int k, int dp[]){
    if(n==0){
        return 1;
    }
    if(n<0){
        return 0;
    }
    if(dp[n]!=0){
        return dp[n];
    }
    int ans = 0;
    for(int jump=1;jump<=k;++jump){
        ans += laddersMemo(n-jump,k,dp);
    }
    return dp[n] = ans;
}

int ladderBottomUp(int n,int k){
    vector<int> dp(n+1,0);
    dp[0] = 1;
    for(int i=1;i<=n;++i){
        for(int jump=1;jump<=k;++jump){
            if(i-jump>=0){
                dp[i] += dp[i-jump];
            }
        }
    }
    return dp[n];
}
int main(){
    int n,k;
    cin>>n>>k;
    //int dp[100000] = {0};
    //cout<<laddersTopDown(n,k,dp);
    //cout<<ladderBottomUp(n,k);
    return 0;
}