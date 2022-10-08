#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;++i){
        cin>>a[i];
    }

    for(int i=1;i<n;++i){
        if(a[i]%a[i-1] == 0 || a[i-1]%a[i]==0){
            int low = min(a[i-1],a[i]);
            a[i] = low;
            a[i-1] = low;
        }
    }
}

int main(){
// #ifndef ONLINE_JUDGE

//     freopen("NUMOFPAIRS.INP", "r", stdin);

//     freopen("NUMOFPAIRS.OUT", "w", stdout);

// #endif // ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int = 1;
    while(t--){
        solve();
    }
    return 0;
}