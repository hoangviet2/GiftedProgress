#include <bits/stdc++.h>

using namespace std;
int dp[10001];
int dpfunc(int current,int n,int a[],int k){
    if(current == n-1){
        return 0;
    }
    if(dp[current] != -1){
        return dp[current];
    }
    int buoc = INT_MAX;
    for(int i = current+1;i<n;++i){
        if(a[i] - a[current] <= k){
            //cout<<i<<" ";
            buoc = min(buoc,dpfunc(i,n,a,k)+1);
        }
    }
    return dp[current] = buoc;
}
int main(){
#ifndef ONLINE_JUDGE

    freopen("input.txt", "r", stdin);

    freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
    int testcase;
    cin>>testcase;
    while(testcase--){
        int n,k;
        cin>>n>>k;
        n += 2;
        int a[n];
        a[0] = 0;
        for(int i=1;i<n;++i){
            cin>>a[i];
        }
        bool reach = false;
        memset(dp,-1,sizeof(dp));
        cout<<dpfunc(0,n,a,k);
    }
    return 0;
}