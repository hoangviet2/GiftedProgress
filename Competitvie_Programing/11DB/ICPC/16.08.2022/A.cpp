#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxN = 2e5+7;
int dp[maxN][2];
void solve(){
    int n;
    string s;
    cin>>n>>s;
    memset(dp,0,sizeof(dp));
    int a[n];
    a[0] = s[0]-'0';
    for(int i=1;i<n;++i){
        a[i] = a[i-1]+s[i]-'0';
    }
    for(int i=0;i<n;++i){
        if(s[i] == '1'){
            dp[i+1][0]=dp[i][1];
            dp[i+1][1]=dp[i][0]+1;
        }else{
            dp[i+1][1]=dp[i][1];
            dp[i+1][0]=dp[i][0]+1;
        }
    }
    ll ans = 0;
    int i = 0;
    for(int j = 1;j<n;++j){
        if((a[j]-a[i-1])%2==0 && i!=0){
            ans+=dp[i][1];
        }else if(a[j]%2==0 && i==0){
            ans+=dp[i][1];
        }
        else{
            ans+=dp[i][0];
        }
        if(s[j]=='1'){
            i=j;
        }
    }
    cout<<ans<<"\n";
}

int main(){
//#ifndef ONLINE_JUDGE
//
//    freopen("input.txt", "r", stdin);
//
//    freopen("output.txt", "w", stdout);
//
//#endif // ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
