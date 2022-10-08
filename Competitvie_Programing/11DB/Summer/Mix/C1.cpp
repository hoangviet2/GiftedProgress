#include <bits/stdc++.h>
using namespace std;
int D,L;

void chuyencoso(int coso,int so,int k){
    int ans = 0;
    int i = 0;
    int j = 0;
    while(so>0){
        if((so%coso)==k){
            if(i-j==0){
                ++ans;
                ++j;
            }
        }
        so/=coso;
        ++i;
    }
    //int tempans = max(ans,L);
    if(ans>L){
        L = ans;
        D = coso;
        return;
    }
    
}

void solve(){
    D = 2;
    L = 0;
    int n,k;
    cin>>n>>k;
    if(n==0 && k == 0){
        cout<<2<<" "<<1;
        return;
    }
    for(int i=2;i<=10;++i){
        chuyencoso(i, n, k);
    }
    cout<<D<<" "<<L;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}
