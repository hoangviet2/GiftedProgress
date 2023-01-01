// 
#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    int n;
    cin>>n;
    ll a=0;
    for(int i=0;i<n;i++){
        ll d;
        cin>>d;
        a = a+d;
    }
    cout<<abs(a)<<"\n";
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