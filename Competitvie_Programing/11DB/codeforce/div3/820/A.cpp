// A. Two Elevators
#include <bits/stdc++.h>
using namespace std;
 
void solve(){
    int a,b,c;
    cin>>a>>b>>c;
    if(b<=c){
        b = b+c;
    }
    cout<<min(a,b)<<"\n";
}
 
int main(){
// #ifndef ONLINE_JUDGE
 
//     freopen("input.txt", "r", stdin);
 
//     freopen("output.txt", "w", stdout);
 
// #endif // ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}