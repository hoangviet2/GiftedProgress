#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
typedef long long ll;
using namespace std;
int main(){
    ll Groups;
    ll sold = 1;
    ll office = 0;
    cin>>Groups;
    for(ll i=0;i<Groups;++i){
        ll temp;
        cin>>temp;
        sold = ((sold%1000000007)*(temp%1000000007))%1000000007;
        office+= temp-1;
    }
    cout<<((sold %1000000007)*(office %1000000007)) %1000000007;
    return 0;
}