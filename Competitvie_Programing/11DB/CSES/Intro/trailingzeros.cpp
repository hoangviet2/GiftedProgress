// Trailing Zeros
#include <bits/stdc++.h>
using namespace std;
#define ll long long


void solve(){
    ll n;
    cin>>n;
    ll total = 0;
    for (ll i = 5; n / i >= 1; i *= 5){
        total += n / i;
    }
    cout << total;
    return;
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