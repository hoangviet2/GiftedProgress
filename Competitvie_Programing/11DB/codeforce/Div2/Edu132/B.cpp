#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    int n,m;
    cin>>n>>m;
    int s[n];
    for(int i=0;i<n;++i){
        cin>>s[i];
    }
    vector<ll> uppers(n,0);
    vector<ll> lowers(n,0);
    for(int i=(n-2);i>=0;--i){
        uppers[i] = uppers[i+1];
        if(s[i]>s[i+1]){
            uppers[i] += s[i]-s[i+1];
        }
    }
    for(int i=1;i<n;++i){
        lowers[i] = lowers[i-1];
        if(s[i]>s[i-1]){
            lowers[i] += s[i]-s[i-1];
        }
    }
    while(m--){
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        //cout<<a<<" "<<b<<"\n";
        if(a<b){
            cout<<abs(uppers[a]-uppers[b])<<"\n";
        }else{
            cout<<abs(lowers[b]-lowers[a])<<"\n";
        }
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
    t =1;
    while (t--){
        solve();
    }
    
    return 0;
}