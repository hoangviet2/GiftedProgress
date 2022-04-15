#include <bits/stdc++.h>
using namespace std;
bool check[3000006];
void Eratosthenes(){
    memset(check, true, sizeof(check));
    check[1] = false;
    for(int i = 2; i <= sqrt(3000001); i++) {
        if(check[i] == true) {
            for(int j = i*i; j <= 3000001; j += i) check[j] = false;
        }
    }
}
bool isable(int n){
    int ans = 0;
    while(n>0){
        ans+=n%10;
        n/=10;
    }
    return ans%5 == 0;

}
int main(){
    freopen("BAI1.INP","r",stdin);
    freopen("BAI1.OUT","w",stdout);
    int testcase;
    cin>>testcase;
    Eratosthenes();
    while(testcase--){
        int a,b;
        cin>>a>>b;
        int ans = 0;
        for(int i=a;i<=b;++i){
            if(isable(i) && check[i]==true){
                ++ans;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}

