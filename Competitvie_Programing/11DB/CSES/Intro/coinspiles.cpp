// Coin Piles
#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int a,b;
    cin>>a>>b;
    cout << ((a + b) % 3 == 0 && (min(a, b) * 2 >= max(a, b)) ? "YES" : "NO") << "\n";
    return;
}

signed main(){
// #ifndef ONLINE_JUDGE

//     freopen("input.txt", "r", stdin);

//     freopen("output.txt", "w", stdout);

// #endif // ONLINE_JUDGE
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