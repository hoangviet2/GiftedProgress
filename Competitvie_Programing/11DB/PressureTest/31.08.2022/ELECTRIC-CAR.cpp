#include<bits/stdc++.h>
#define ll long long
const int maxN = 200007;
using namespace std;

ll a[maxN];
void solve(){
    int n,m;
    ll L,R;
    cin>>n>>m>>L>>R;
    for(int i=1; i<=m; ++i){
        cin>>a[i];
    }
    sort(a+1, a+m+1);
    ll maxs = 0;
    for(int i=1; i<=m; ++i){
        if(i==1 && L<a[i]){
            maxs = max(maxs, a[i]-L);
        }
        if(i==m && R>a[i]){
            maxs = max(maxs, R-a[i]);
        }
        if(i>1 && i<=m){
            if((a[i]+a[i-1])%2==0 && L<=(a[i]+a[i-1])/2 && (a[i]+a[i-1])/2<=R){
                maxs = max(maxs, a[i]-(a[i]+a[i-1])/2);
            }else if((a[i]+a[i-1])%2==0){
                if(a[i-1]<=R && R<(a[i]+a[i-1])/2){
                    maxs = max(maxs, R-a[i-1]);
                }else if((a[i]+a[i-1])/2<L && L<=a[i]){
                    maxs = max(maxs, a[i]-L);
                }
            }
        }
    }
    cout<<maxs;
}
int main(){
#ifndef ONLINE_JUDGE
   freopen("ELECTRIC-CAR.INP" ,"r" ,stdin);
   freopen("ELECTRIC-CAR.OUT" ,"w" ,stdout);
#endif // ONLINE_JUDGE
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}
