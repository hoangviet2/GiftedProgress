// Bài bịp =)))
#include <bits/stdc++.h>
using namespace std;

void solve(){
    int a,b,c;
    cin>>a>>b>>c;
    for(int i=0;a*i <= c;++i){
        int wtfc = c - (a*i);
        if(wtfc%b == 0){
            cout<<"YES";
            return;
        }
    }
    cout<<"NO";
}

int main(){
#ifndef ONLINE_JUDGE

    freopen("input.txt", "r", stdin);

    freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    t = 1;
    while(t--){
        solve();
    }
    return 0;
}