#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll powr(ll a,ll n){
    ll ans = 1;
    while(n>0){
        if(n%2==1){
            ans *= a;
        }
        a *= a;
        n /= 2;
    }
    return ans;
}

void solve(){
    ll n;
    vector<ll> a;
    while(cin>>n){
        if(n==0){
            break;
        }
        a.push_back(n);
    }
    sort(a.begin(),a.end());
    ll got = 0;
    int powers = 1;
    for(int i=a.size()-1;i>=0;--i){
        got += 2*powr(a[i],powers);
        ++powers;
    }
    if(got>5000000){
        cout<<"Too expensive\n";
    }else{
        cout<<got<<"\n";
    }
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
        solve();
    }
    return 0;
}