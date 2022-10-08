// Subarray Sums II,I
#include <bits/stdc++.h>
using namespace std;
#define ll long long
map<ll,int> mapple;

void solve(){
    int n, x;
    cin>>n>>x;
    vector<int> a(n);
    for(int i=0;i<n;++i){
        cin>>a[i];
    }
    ll prefix = 0;
    mapple[0] = 1;
    ll ans = 0;
    for(auto i:a){
        prefix += i;
        ans += mapple[prefix-x];
        mapple[prefix]++;
    }
    cout<<ans;
}

int main(){
#ifndef ONLINE_JUDGE

    freopen("input.txt", "r", stdin);

    freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //cout<<"Hello world"<<"\n";
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}