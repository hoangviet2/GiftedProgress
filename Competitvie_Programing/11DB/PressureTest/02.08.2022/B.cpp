#include <bits/stdc++.h>
using namespace std;
#define maxN 1000000
#define int long long
vector<int> sieve(maxN,1);

int minPow(int a,int l){
    int ans = 0;
    int currentA = 1
    while(currentA<=l){
        currentA*=a;
        ++ans;
    }
    return ans--;
}

int maxPow(int a,int r){
    int ans = 0;
    int currentA = 1;
    while(currentA<r){
        currentA*=a;
        ++ans;
    }
    return ans;
}

void primeSieve(){
    sieve[0] = sieve[1] = 0;
    for(int i=2;i<=maxN;++i){
        if(sieve[i]){
            for(int j= i*i ; j<=maxN;j+=i){
                sieve[j] = 0;
            }
        }
    }
}

signed main(){
#ifndef ONLINE_JUDGE

    freopen("input.txt", "r", stdin);

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
        int ans = 0;
        int temp_ans = 0;
    
    }
}