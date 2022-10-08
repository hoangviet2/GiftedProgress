#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    ll ans = 0;
    int n,k;
    vector<int> indexs;
    cin>>n>>k;
    for(int i=1;i<=n;++i){
        int temp;
        cin>>temp;
        if(temp%k == 0){
            indexs.push_back(i);
        }
    }
    int indIndexs = 0;
    for(int i=1;i<=n;++i){
        if(indIndexs+1 >= indexs.size()){
            ans += n+1-i;
        }else{
            ans += indexs[indIndexs+1]-i;
            if(i == indexs[indIndexs]){
                indIndexs++;
            }
        }
    }
    cout<<ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //cout<<"Hello world"<<"\n";
    int t;
    t = 1;
    while(t--){
        solve();
    }
    return 0;
}
