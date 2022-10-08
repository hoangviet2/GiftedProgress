// Two Knights
#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    ll n;
    cin>>n;
    for(ll i = 1;i<=n;++i){
        cout<<(i*i)*(i*i-1)/2 - (4*(i-2)*(i-1))<<"\n";
    }
}

int main(){
// #ifndef ONLINE_JUDGE

//     freopen("input.txt", "r", stdin);

//     freopen("output.txt", "w", stdout);

// #endif // ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t =1;
    while(t--){
        solve();
    }
    return 0;
}