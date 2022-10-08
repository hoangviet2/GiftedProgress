#include <bits/stdc++.h>
using namespace std;
//const int maxN = 1e9+1;
//int dp[maxN];

void solve(){
    int n;
    cin>>n;
    cout<<dpfunc(0,abs(n),0)-1<<"\n";
}

int main(){
#ifndef ONLINE_JUDGE

    freopen("input.txt", "r", stdin);

    freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        for(int i=0;i<5;++i){
            for(int j=0;j<idiot[i].size();++i){
                cout<<idiot[i][j]<<" ";
            }
            cout<<"\n";
        }
        //memset(dp,-1,sizeof(dp));
        solve();
    }
    return 0;
}