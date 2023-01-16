#include <iostream>
typedef long long ll;
using namespace std;

int main(){
    int testcase;
    cin>>testcase;
    while(testcase--){
        ll cars;
        ll ans = 0;
        cin>>cars;
        for(ll i=0;i<cars;++i){
            ll temp;
            cin>>temp;
            ans+=temp;
        }
        if(ans%2==0){
            cout<<ans/2<<"\n";
        }else{
            cout<<(ans+1)/2<<"\n";
        }
    }
    return 0;
}