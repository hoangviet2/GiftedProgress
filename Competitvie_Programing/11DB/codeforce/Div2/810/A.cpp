#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    if(n==1){
        cout<<1<<"\n";
        return;
    }
    int chan = 2;
    int le = 1;
    if(n%2){
        cout<<1<<" ";
        le+=2;
        for(int i=1;i<n;++i){
            if(i%2 == 0){
                cout<<chan<<" ";
                chan+=2;
            }else{
                cout<<le<<" ";
                le+=2;
            }
        }
    }else{
        for(int i=0;i<n;++i){
            if(i%2 == 0){
                cout<<chan<<" ";
                chan+=2;
            }else{
                cout<<le<<" ";
                le+=2;
            }
        }
    }
    
    cout<<"\n";
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