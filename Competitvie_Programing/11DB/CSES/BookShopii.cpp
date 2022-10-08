#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxN = 100+7;
const int maxX = 1e5+7;
int h[maxN], s[maxN], k[maxN];
ll dp[maxX];
void solve(){
    int n,x;
    cin>>n>>x;
    for(int i=0;i<n;++i){
        cin>>h[i];
    }
    for(int i=0;i<n;++i){
        cin>>s[i];
    }
    for(int i=0;i<n;++i){
        cin>>k[i];
    }
    for(int i=1;i<x+1;++i){
        dp[i] = -1;
    }
    for(int a = 0;a<n;++a){
        for(int b = 1;k[a]>0;b++){
            // how many books are there
            int bookss = min(b,k[a]);
            k[a]-=b;
            // total cost with books
            int prices = bookss*h[a];
            // total pages with books
            int pages = bookss*s[a];
            for(int c = x; c >= prices; --c){
                if(dp[c-prices] != -1){
                    dp[c] = max(dp[c],dp[c-prices]+pages);
                }
            }
        }
    }
    for(int i = 1;i<=x;++i){
        dp[i] = max(dp[i-1],dp[i]);
    }
    cout<<dp[x]<<"\n";
    return;
}

int main(){
// #ifndef ONLINE_JUDGE

//     freopen("input.txt", "r", stdin);

//     freopen("output.txt", "w", stdout);

// #endif // ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}