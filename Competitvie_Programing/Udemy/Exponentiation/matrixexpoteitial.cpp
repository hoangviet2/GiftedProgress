#include <bits/stdc++.h>
using namespace std;
const int sz = 2;
const int mod  = 1e9 + 7;
struct mat{
    int m[sz][sz];
    mat(){
        memset(m,0,sizeof(m));
    }
    void indentity(){
        for(int i=0;i<sz;++i){
            m[sz][sz] = 1;
        }
    }
    mat operator*(mat a){
        mat res;
        for(int i=0;i<sz;++i){
            for(int j=0;j<sz;++j){
                for(int k=0;k<sz;++k){
                    res.m[i][j] += m[i][k]*a.m[k][j]; 
                    res.m[i][j] %= mod;
                }
            }
        }
        return res;
    }
};

int fib(int n){
    mat res;
    res.indentity();
    mat temp;
    temp.m[0][0] = temp.m[0][1] = temp.m[1][0] = 1;

    if(n<=2){
        return 1;
    }
    n-=2;

    while(n){
        if(n&1){
            res = res * temp;
        }
        temp = temp*temp;
        n/=2;
    }
    return (res.m[0][0]+res.m[0][1])%mod;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout<<fib(4);
    return 0;
}