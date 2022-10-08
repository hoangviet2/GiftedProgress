#include <bits/stdc++.h>
using namespace std;
#define maxN 100000
#define ll long long
int sieve[maxN+1] = {0};
vector<int> primes;
void primeSieve(){
    for(ll i = 2;i<=maxN;++i){
        if(sieve[i] == 0){
            primes.push_back(i);
        }
        for(ll j = i*i;j<=maxN;j+=i){
            sieve[j] = 1;
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
    primeSieve();
    int t;
    cin>>t;
    while (t--){
        int n,m;
        cin>>m>>n;
        vector<int> segment(n-m+1,0);
        for(int p:primes){
            if(p*p > n){
                break;
            }
            int start_point = (m/p)*p;

            // special case
            if(p>=m && p<=n){
                start_point = 2*p;
            }

            for(int j=start_point;j<=n;j+=p){
                if(j<m){
                    continue;
                }
                // non = prime
                segment[j-m] = 1;
            }
        }
        for(int i=m;i<=n;++i){
            if(segment[i-m] == 0 && i!=1){
                cout<<i<<" ";
            }
        }
    }
    
    return 0;
}