#include <iostream>
#include <map>
#include <algorithm>
#include <numeric> 
using namespace std;
typedef long long ll;

int main(int argc, char** argv)
{
    ll n,temp;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    map<ll,int> a;
    cin >> n;                    
    for (ll i = 0; i < n; i++){
        cin >> temp;
        a[temp] = 1;
    }
    cin>>n;
    for(ll i =0;i<n;++i){
        cin>>temp;
        if(a[temp] !=0){
            cout<<"YES"<<"\n";
        }else{
            cout<<"NO"<<"\n";
        }
    }
}
