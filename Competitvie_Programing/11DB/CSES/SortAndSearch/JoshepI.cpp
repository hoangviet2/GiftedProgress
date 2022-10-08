// Josephus Problem I
#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin>>n;
    int a = 1, b = 0;
    while(n > 0) {
    	for (int i = 2; i <= n; i+=2) {
    		cout<<a*i + b<<' ';
    	}
    	if (n&1) cout<<a + b<<' ', b += a;
    	else b -= a;
    	a <<= 1;
    	n >>= 1;
    }

}


int main(){
// #ifndef ONLINE_JUDGE

//     freopen("input.txt", "r", stdin);

//     freopen("output.txt", "w", stdout);

// #endif // ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
