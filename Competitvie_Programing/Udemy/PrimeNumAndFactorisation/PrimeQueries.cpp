#include <bits/stdc++.h>
#define maxN 1000001
#define ll long long
using namespace std;

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

int main(){
#ifndef ONLINE_JUDGE

    //freopen("input.txt", "r", stdin);

    freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> sieve(maxN,1);
    vector<ll> prefixSum(maxN,0);
    primeSeive(sieve);
    for(){
        
    }
    return 0;
}