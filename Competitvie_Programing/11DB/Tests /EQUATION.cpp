#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void slove(ll a, ll b){
    ll hi=a*b, cnt=1, lo=hi;
    hi=hi*hi;
    for(ll y=hi; y>sqrt(hi); --y){
        ll x=hi/y;
        if(x+y==hi && lo*2!=y)
            cnt+=2;
    }
    cout<<cnt<<"\n";
}
int main(){
    freopen("EQUATION.INP", "r", stdin);
    freopen("EQUATION.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        ll a, b;
        cin>>a>>b;
        slove(a,b);
    }
}
