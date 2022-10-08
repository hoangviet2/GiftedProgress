#include<bits/stdc++.h>
using namespace std;
long long dp[100005];
const int MOD = 1e9+7;
int main(){
// #ifndef ONLINE_JUDGE

//     freopen("input.txt", "r", stdin);

//     freopen("output.txt", "w", stdout);

// #endif // ONLINE_JUDGE
    dp[0] = 1;
    dp[1] = 1;
    string s;
    cin>>s;
    int n = s.length();
    for(int i=0;i<s.length();++i){
        if(s[i] == 'm' || s[i] == 'w'){
            cout<<0;
            return 0;
        }
    }
    for(int i=2; i<=n; ++i){
        if((s[i-1] == 'n' && s[i-2]=='n' || s[i-1]=='u' && s[i-2]=='u')){
            dp[i] = (dp[i-2]+dp[i-1])%MOD;
        }else{
            dp[i] = dp[i-1];
        }
    }
    cout<<dp[n];
}