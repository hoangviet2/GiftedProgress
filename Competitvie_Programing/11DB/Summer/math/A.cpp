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
int main(){
#ifndef ONLINE_JUDGE

    //freopen("input.txt", "r", stdin);

    freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //cout<<"Hello world"<<"\n";
    ll n;
    cin>>n;
    cout<<24*powr(4,n-3) + 36*powr(4,n-4)*(n-3);
    return 0;
}