//
#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    int mins = INT_MAX;
    int a[n];
    for(int i=0;i<n;++i){
        cin>>a[i];
        mins = min(a[i],mins);
    }
    int ans = 0;
    for(auto &x:a){
        if(x>=2*mins){
            ans += (x - 2 * mins) / (2 * mins - 1) + 1;
        }
    }
    cout<<ans<<"\n";
}

int main(){
#ifndef ONLINE_JUDGE

    freopen("input.txt", "r", stdin);

    freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //cout<<"Hello world"<<"\n";
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}