#include <iostream>
#include <set>
using namespace std;
typedef long long ll;
ll n,temp;
set<ll> a;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;                
    for (ll i = 1; i <= n; i++){
        cin>>temp;
        a.insert(temp);
    }
    cout<<a.size()<<"\n";
    for(auto element:a){
        cout<<element<<" ";
    }
}