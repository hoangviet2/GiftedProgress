// 
#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    int n,s;
    cin>>n>>s;
    bool a[2000];
    int sum = 0;
    for(int i=0;i<n;++i){
        int temp;
        cin>>temp;
        
    }
    for(int i=0;i<2007;++i){
        if(a[i] == (sum+s)){
            cout<<"YES\n";
            return;
        }
    }
    cout<<"NO\n";

}

int main(){
#ifndef ONLINE_JUDGE

    freopen("input.txt", "r", stdin);

    freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);
    preprocess();
    int t = 1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}