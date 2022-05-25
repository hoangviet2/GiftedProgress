#include <iostream>

using namespace std;
int fib(int n,int dp[]){
    if(n==1||n==0){
        return n;
    }
    if(dp[n]!=0){
        return dp[n];
    }
    return dp[n] = fib(n-1,dp)+fib(n-2,dp);
}
int main(){
    int memo[100000];
    cout<<fib(5,memo);

    return 0;
}