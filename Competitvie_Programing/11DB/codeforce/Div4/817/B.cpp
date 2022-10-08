#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    string s,t;
    for(int i=0;i<n;++i){
        char ch;
        cin>>ch;
        if(ch == 'B'){
            s += 'G';
        }else{
            s += ch;
        }
    }
    for(int i=0;i<n;++i){
        char ch;
        cin>>ch;
        if(ch == 'B'){
            t += 'G';
        }else{
            t += ch;
        }
    }
    if(s==t){
        cout<<"YES\n";
        return;
    }
    cout<<"NO\n";

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
