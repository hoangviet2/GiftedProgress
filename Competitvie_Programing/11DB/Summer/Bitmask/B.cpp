#include <bits/stdc++.h>
using namespace std;
const int maxN = 1e4+7;

int a[4][maxN];
int dp[maxN][(1<<4)+7];

bool check(int x){
    for(int i=0; i<4; i++){
        if( ((x>>i)&1)==1 && ((x>>(i+1))&1)==1){
            return false;
        }
    }
    return true;
}

void solve(){
    int n;
    cin>>n;
    int maxsElem = INT_MIN;
    for(int i = 0;i<4;++i){
        for(int j=1;j<=n;++j){
            cin>>a[i][j];
            maxsElem = max(a[i][j],maxsElem);
        }
    }
    for(int i=1;i<=n;i++){
        for(int bit =0 ; bit <16 ;bit++ ){
            if (!check(bit))
                continue;
            int temp = 0;
            for(int j=0;j<4;j++){
                if((bit>>j)&1){
                    temp+=a[j][i];
                }
            }
            for(int prebit=0; prebit <16; prebit++){
                if(!check(prebit)){
                    continue;
                }
                if((bit&prebit)==0){
                    dp[i][bit] = max(dp[i][bit], dp[i-1][prebit]+temp );
                }
            }
        }
    }
    int ans = 0;
    for(int bit=0;bit<16;bit++)
    {
        ans = max(dp[n][bit],ans);
    }
    if(maxsElem < 0) ans = maxsElem;
    cout<<ans;
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