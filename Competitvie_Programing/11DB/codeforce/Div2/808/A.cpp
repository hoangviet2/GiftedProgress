#include <bits/stdc++.h>
using namespace std;

void slove(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;++i){
        cin>>a[i];
    }
    bool isvalid = false;
    for(int i = 1;i<n;++i){
        if(a[i] % a[0]){
            isvalid = 1;
        }
    }
    if(isvalid){
        cout<<"NO\n";
    }else{
        cout<<"YES\n";
    }
}

int main(){
#ifndef ONLINE_JUDGE

    //freopen("input.txt", "r", stdin);

    freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //cout<<"Hello world"<<"\n";
    int t;
    cin>>t;
    while(t--){
        slove();
    }
    return 0;
}