// MOD10
#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<int> a(10);
ll ans = 0;
map<ll,ll>m;
ll returnval(int n){
    ll temp = 0;
    while(n){
        temp+=a[n%10];
        n/=10;
    }
    return temp;
}
void preprocess(){
    a[0] = 1;
    a[1] = 1;
    a[2] = 2;
    a[3] = 6;
    a[4] = 24;
    a[5] = 120;
    a[6] = 720;
    a[7] = 5040;
    a[8] = 40320;
    a[9] = 362880;
}
void solve(){
    int n;
    cin>>n;
    if(n==1){
        cout<<0;
        return;
    }
    while(n){
        int upper = upper_bound(a.begin(),a.end(),n)-a.begin();
        int times = n/a[upper-1];
        m[upper-1] = times;
        n %= a[upper-1];
    }
    for(auto x:m){
        for(int i=0;i<x.second;++i){
            cout<<x.first;
        }
        //cout<<x.first<<" "<<x.second<<"\n";
    }
    
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt","w", stdout);
#endif // ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);
    int t = 1;
    preprocess();
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}