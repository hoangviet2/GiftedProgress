// Goldbach's Conjecture
#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n){
    for(int i=2;i*i<=n;++i){
        if(n%i == 0){
            return false;
        }
    }
    return true;
}

void solve(){
    int a;
    while(cin>>a){
        if(a==0){
            return;
        }
        cout<<a<<" = ";
        for(int i=2;i<a;++i){
            if(isPrime(i) && isPrime(a-i)){
                cout<<i<<" + "<<a-i<<"\n";
                break;
            }
        }
    }
}

int main(){
// #ifndef ONLINE_JUDGE

//     freopen("input.txt", "r", stdin);

//     freopen("output.txt", "w", stdout);

// #endif // ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //cout<<"Hello world"<<"\n";
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}