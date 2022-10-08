// Weird Algorithm
#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    ll n;
    cin>>n;
    cout<<n<<" ";
    while(n!=1){
        if(n%2){
            n*=3;
            n+=1;
        }else{
            n/=2;
        }
        cout<<n<<" ";
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}