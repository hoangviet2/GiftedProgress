// Increasing Array
#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    int n;
    cin>>n;
    ll ans = 0;
    int pre;
    cin>>pre;
    int temp;
    for(int i=1;i<n;++i){
        cin>>temp;
        if(temp<=pre){
            ans += abs(temp-pre);
        }else{
            pre = temp;
        }

    }
    cout<<ans<<"\n";
}

int main(){
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);

//     freopen("output.txt", "w", stdout);

// #endif // ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}