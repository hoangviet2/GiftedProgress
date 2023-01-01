// 
#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    ll n;
    cin>>n;
    cout<<(n+1)/2<<"\n";
    for(int i=0;i<(n+1)/2;++i){
        cout<<(i*3)+1<<" "<<n*3-(i*3+1)+1<<"\n";
    }
}

int main(){
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