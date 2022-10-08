#include <bits/stdc++.h>
using namespace std;
const int P = 5, maxN = 1e5;
int fact[maxN];
int addmod(int a,int b){
    return (a+b)%P;
}
int submod(int a,int b){
    return ((a-b)%P + P) % P;
}

int mulmod(int a,int b){
    return (a*b)%P;
}

int powmod(int a,int b){
    int res = 1;
    while(b){
        if(b & 1){
            res = mulmod(res,a);
        }
        b/=2;
        a = mulmod(a,a); 
    }
    return res;
}

int divmod(int a,int b){
    return mulmod(a,powmod(b,P-2));
}

void calculateFactorialMod(){
    fact[0] = 1;
    for(int i=1;i<maxN;++i){
        fact[i] = mulmod(fact[i-1],i);
    }
}

int main(){
#ifndef ONLINE_JUDGE

    freopen("input.txt", "r", stdin);

    freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout<<"Hello world"<<"\n";
    return 0;
}