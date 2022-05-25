#include <iostream>
#include <vector>
using namespace std;
int n;
vector<int> h,dp;
void readata(){
    cin>>n;
    h.resize(n);
    for(int i=0;i<n;++i){
        cin>>h[i];
    }
    return;
}
void dpFunc(){
    dp.resize(n);
    dp[0] = 0;
    dp[1] = dp[0] + abs(h[1]-h[0]);
    for(int i = 2;i<n;++i){
        dp[i] = min(dp[i-1] + abs(h[i-1] - h[i]),dp[i-2] + abs(h[i-2] - h[i]));
    }
    return;
}
int main(){
    readata();
    dpFunc();
    cout<<dp[n-1];
    return 0;
}