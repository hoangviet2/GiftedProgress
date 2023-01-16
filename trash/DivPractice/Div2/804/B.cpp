#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
void slove(){
    for(ll i=1;i<=n;++i){
        for(ll j=1;j<=m;++j){
            cout<<((i%4<=1)!=(j%4<=1))<<" \n"[j==m];
        }
    }

    return;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //cout<<"Hello world"<<"\n";
    int testcase;
    cin>>testcase;
    while(testcase--){
        cin>>n>>m;
        slove();
    }
    return 0;
}