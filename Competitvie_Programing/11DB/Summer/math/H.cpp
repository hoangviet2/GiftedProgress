#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxN 100007

vector<int> sieve(maxN,1);
void primeSeive(vector<int> &sieve){
    sieve[0] = sieve[1] = 0;
    for(ll i=2;i<=maxN;++i){
        if(sieve[i]){
            for(ll j= i*i ; j<=maxN;j+=i){
                sieve[j] = 0;
            }
        }
    }
}

void solve(){
    int n;
    cin>>n;
    if(n<=2){
        cout<<1<<"\n";
    }else{
        cout<<2<<"\n";
    }
    for(int i=2;i<=n+1;++i){
        if(!sieve[i]){
            cout<<2<<" ";
        }else{
            cout<<1<<" ";
        }
    }
}
int main(){
#ifndef ONLINE_JUDGE

    freopen("input.txt", "r", stdin);

    freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    primeSeive(sieve);
    int t;
    t = 1;
    while(t--){
        solve();
    }
    return 0;
}