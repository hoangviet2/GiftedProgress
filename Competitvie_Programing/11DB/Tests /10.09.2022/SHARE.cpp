#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxN = 1e5+7;
void solve(){
    ll n,m;
    cin>>n>>m;
    ll a[maxN];
    ll total = 0;
    for(int i=0;i<n;++i){
        cin>>a[i];
        total += a[i];
    }
    if(total<m){
        cout<<-1;
        return;
    }
    int average = m/n;
    int cnt = 0;
    for(int i=0;i<n;++i){
        if(a[i]<=average){
            m-=a[i];
            cnt++;
        }
    }
    int haveleft = m/(n-cnt);
    // m%(n-cnt) always fit;
    int mods = m%(n-cnt);
    for(int i=0;i<n;++i){
        if(a[i]<=average){
            cout<<a[i]<<" ";
        }else{
            if(mods && haveleft+1 <= a[i]){
                cout<<haveleft+1<<" ";
                --mods;
            }else{
                cout<<haveleft<<" ";
            }
        }
    }

}

int main(){
#ifndef ONLINE_JUDGE

    freopen("SHARE.INP", "r", stdin);

    freopen("SHARE.OUT", "w", stdout);

#endif // ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
