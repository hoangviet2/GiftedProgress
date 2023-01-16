// Gardener and the Capybaras (easy version)
// Gardener and the Capybaras (hard version)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    string s;
    cin>>s;
    int pos = 0;
    int n = s.length();
    for(int i=0;i<n;++i){
        if(s[i]=='a'){
            pos = i;
            break;
        }
    }
    if(pos){
        cout<<s.substr(0,pos)<<" a "<<s.substr(pos+1)<<"\n";
    }else{
        cout<<s[0]<<" "<<s.substr(1,n-2)<<" "<<s[n-1]<<"\n";
    }
}

int main(){
#ifndef ONLINE_JUDGE

    freopen("input.txt", "r", stdin);

    freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);
    int t = 1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}