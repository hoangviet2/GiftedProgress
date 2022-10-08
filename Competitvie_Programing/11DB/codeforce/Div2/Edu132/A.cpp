#include <bits/stdc++.h>
using namespace std;

void solve(){
    int a[3];
    int key;
    cin>>key;
    int sum = 0;
    for(int i=0;i<3;++i){
        cin>>a[i];
    }
    int isvalid = 0;
    while(a[key-1] != 0){
        ++isvalid;
        key = a[key-1];
    }
    if(isvalid == 2){
        cout<<"YES\n";
    }else{
        cout<<"NO\n";
    }
}

int main(){
#ifndef ONLINE_JUDGE

    //freopen("input.txt", "r", stdin);

    freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}