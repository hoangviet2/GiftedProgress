// Repetitions
#include <bits/stdc++.h>
using namespace std;

void solve(){
    string s;
    cin>>s;
    int dp[s.size()];
    dp[0] = 1;
    int maxs = dp[0];
    for(int i=1;i<s.size();++i){
        if(s[i-1] == s[i]){
            dp[i] = dp[i-1]+1;
        }else{
            dp[i] = 1;
        }
        maxs = max(dp[i],maxs);
    }
    cout<<maxs;
}

int main(){
// #ifndef ONLINE_JUDGE

//     freopen("input.txt", "r", stdin);

//     freopen("output.txt", "w", stdout);

// #endif // ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //cout<<"Hello world"<<"\n";
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}