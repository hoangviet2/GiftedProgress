#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;

long long power(long long a,long long n){
    long long p;
    if(n==0){
        return 1;
    }
    p=power(a,n/2);
    p=(p*p)%mod;
    if(n%2){
        p=(p*a)%mod;
    }
    return p;
}

int locker(int n){
    int ans = 1;
    if(n<2){
        ans = n;
    }else{
        int cnt = n/3;
        int rem = n%3;
        if(rem==1){
            ans=(power(3,cnt-1)*4)%mod;
        }
        else if(rem==2){
            ans=(power(3,cnt)*2)%mod;
        }
        else{
            ans=power(3,cnt);
        }
    }
    return ans;
}
int main() {
	// your code goes here
    cout<<locker(4);
	return 0;
}

