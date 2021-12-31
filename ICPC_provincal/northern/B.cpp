#include <iostream>
#include <map>
#include <utility>
typedef long long ll;
using namespace std;
int main(){
    ll n;
    ll ans = 0;
    cin>>n;
    for(ll i=0;i<n;++i){
        ll temp;
        cin>>temp;
        ans += temp;
    }
    if(ans!=0){
        cout<<ans*(-1);
    }
    return 0;
}