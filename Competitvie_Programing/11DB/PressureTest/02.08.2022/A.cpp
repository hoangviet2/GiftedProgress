#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    ll n;
    cin>>n;
    string s;
    while(n>0){
        if(n%2){
            n-=1;
            s+='D';
        }else{
            n/=2;
            s+='T';
        }
    }
    reverse(s.begin(),s.end());
    cout<<s;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    t = 1;
    while(t--){
        solve();
    }
    return 0;
}