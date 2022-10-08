#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9+7;
ll powr(ll a,ll n){
    ll ans = 1;
    while(n>0){
        if(n%2==1){
            ans *= a;
            ans %= mod;
        }
        a *= a;
        a %= mod;
        n /= 2;
    }
    return ans;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        if(n<3){
            cout<<n<<"\n";
        }else{
            if(n%3==0){
                cout<<(powr(3,n/3))%mod<<'\n';
            }else if(n%3==1){
                cout<<(powr(3,((n-1)/3)-1)*4)%mod<<"\n";
            }else{
                cout<<(powr(3,(n-2)/3)*2)%mod<<"\n";
            }
        }
    }
    return 0;
}