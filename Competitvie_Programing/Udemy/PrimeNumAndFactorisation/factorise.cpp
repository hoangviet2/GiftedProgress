#include <bits/stdc++.h>
using namespace std;
#define maxN 1000000
#define ll long long
void primeSeive(vector<int> &sieve){
    for(int i=1; i<=N; i++){
		sieve[i] = i;
	}
    
    for(ll i=2;i<=maxN;++i){
        if(sieve[i]){
            for(ll j= i*i ; j<=maxN;j+=i){
                sieve[j] = i;
            }
        }
    }
}

// brute force
void factories(){
    int n;
    cin>>n;
    cout<<n<<": ";
    for(int i=2;i<=n;++i){
        if(n%i==0){
            int cnt = 0;
            while(n%i==0){
                n/=i;
                cnt++;
            }
            cout<<i<<"^"<<cnt<<",";
        }
    }
}

// Optimised Approach
void factoriesSqrt(){
    int n;
    cin>>n;
    cout<<n<<": ";
    for(int i=2;i*i<=n;++i){
        if(n%i==0){
            int cnt = 0;
            while(n%i==0){
                n/=i;
                cnt++;
            }
            cout<<i<<"^"<<cnt<<",";
        }
    }
    if(n!=1){
        cout<<n<<"^1";
    }
}

// optimised optimised apporach
void sieveFactorise(){
    int n;
    cin>>n;
    vector<int> sieve(maxN+1,0);
    primeSeive(sieve);
    for(int i=0;i<n;++i){
        cout<<sieve[i];
    }
}

int main(){
#ifndef ONLINE_JUDGE

    //freopen("input.txt", "r", stdin);

    freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    t = 1;
    while(t--){
        sieveFactorise();
    }
    return 0;
}