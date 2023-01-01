#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    ll x,y;
    cin >> x >> y;
    if (x < y){
        if (y % 2 == 1){
            ll r = y * y;
            cout << r - x + 1 << "\n";
        }else{
            ll r = (y - 1) * (y - 1) + 1;
            cout << r + x - 1 << "\n";
        }
    }else{
        if (x % 2 == 0){
            ll r = x * x;
            cout << r - y + 1 << "\n";
        }else{
            ll r = (x - 1) * (x - 1) + 1;
            cout << r + y - 1 << "\n";
        }
    }
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
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}