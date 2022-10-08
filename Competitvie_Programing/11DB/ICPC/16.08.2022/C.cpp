#include <bits/stdc++.h>
using namespace std;
#define ll long long

int GCD(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}
void solve(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;++i){
        cin>>a[i];
    }
    ll prefix = 0;
    int gcds = 0;
    for(int i=0;i<n;++i){
        prefix += a[i];
        gcds = GCD(gcds,a[i]);
    }
    cout<<prefix<<" "<<gcds<<"\n";
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
