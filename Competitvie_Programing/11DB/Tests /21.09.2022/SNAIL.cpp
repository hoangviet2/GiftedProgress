// SNAIL
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9+7;

void solve(){
    ll h,n;
    cin>>h>>n;
    ll a[n+1];
    a[0] = 0;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        a[i] += a[i-1];
        if(a[i]>=h){
            cout<<0<<" "<<i-1;
            return;
        }
    }
    if(a[n]<0){
        cout<<-1<<" "<<-1;
        return;
    }
    ll b[n+1];
    ll mins = INT_MAX;
    for(int i=1;i<=n;++i){
        b[i] = ceil((h-a[i])/a[n]);
        mins = min(mins,b[i]);
    }
    cout<<mins+1<<" ";
    for(int i=1;i<=n;++i){
        if(b[i] == mins){
            cout<<i-1;
        }
    }
    return;
}

int main(){
// #ifndef ONLINE_JUDGE
//     freopen("SNAIL.INP","r",stdin);

//     freopen("SNAIL.OUT","w",stdout);
// #endif // ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}