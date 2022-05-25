#include <iostream>
#include <vector>
using namespace std;
#define maxn 100001
long long solve(int n, vector<int> a){
    vector<long long> dp(maxn),cnt(maxn);
    // cnt đếm cái phần tử xuất hiện bao nhiu lần
    for(int i=0;i<n;++i){
        cnt[a[i]]++;
    }
    dp[0] = 0;
    dp[1] = cnt[1];
    long long ans = dp[1];
    for(int i=2;i<maxn;++i){
        long long val = i*cnt[i];
        dp[i] = max(dp[i-1],val+dp[i-2]);// xoá dp[i-1] hay xoá dp[i-2] và dp[i] (val)
        ans = max(ans,dp[i]);
    }
    return ans;
}

int main() {
    cout<<solve(9,vector<int> {1,2,1,3,2,2,2,2,3});
    // your code goes here
    return 0;
}
