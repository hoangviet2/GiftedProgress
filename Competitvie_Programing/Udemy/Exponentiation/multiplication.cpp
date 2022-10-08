#include <bits/stdc++.h>
#define int long long
using namespace std;
int multiply(int a,int b,int c){
    int ans = 0;
    while(b){
        if(b&1){
            ans += a;
            ans %= c;
        }
        a *= 2;
        a %= c;
        b /= 2;
    }
    return ans;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout<<multiply(10000000000009,111213123123123123,1020999990909);
    return 0;
}