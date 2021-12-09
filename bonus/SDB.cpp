#include <iostream>
#include <math.h>
#include <fstream>
#include <vector>
#include <map>
typedef long long ll;
using namespace std;
vector<ll> data = {36,225,441,1089,1521,2601,3249,4761,6561,7569,8649,12321,15129,16641,19881,25281,31329,33489,40401,45369,47961,56169,62001,71289,84681,91809,95481};
map<ll,bool> sets;
void setData(){
    for(auto element:data){
        sets[element] = true;
    }
    return;
}
bool isValid(ll n){
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        if(n % i == 0) {
            ++ans;
        }
    }
    return ans==9;
}
int main(){
    freopen("SDB.Inp","r",stdin);
    freopen("SDB.Out","a",stdout);
    setData();
    int testcase;
    cin>>testcase;
    while(testcase>0){
        ll a,b;
        ll ans = 0;
        cin>>a>>b;
        for(ll i=a;i<=b;++i){
            if(sets[i]==true){
                ++ans;
            }
        }
        cout<<ans<<"\n";
        --testcase;
    }
    return 0;
}
