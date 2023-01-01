// 
#include <bits/stdc++.h>
using namespace std;
#define ll long long
void supersolve(int cnt,vector<int> v,int n){
    ll ans=0;
    if(cnt>=n){
        cout<<0<<"\n";
        return;
    }else{
        for(int i=0;i<v.size();i++){
            cnt+=v[i];
            ans++;
            if(cnt>=n){
                cout<<ans<<"\n";
                return;
            }
        }
    }
    cout<<-1<<"\n";
}
void solve(){
    int n;
    cin>>n;
    vector<int> v;
    int a[n];
    ll cnt=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        while(a[i]%2==0){
            cnt++;
            a[i]/=2;
        }
        ll x=i;
        ll cnt2i=0;
        while(x%2==0){
            cnt2i++;
            x/=2;
        }
        v.push_back(cnt2i);
    }
    
    sort(v.begin(),v.end(),greater<ll>());
    supersolve(cnt,v,n);
}

int main(){
#ifndef ONLINE_JUDGE

    freopen("input.txt", "r", stdin);

    freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);
    int t = 1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}