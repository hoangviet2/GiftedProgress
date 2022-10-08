#include <bits/stdc++.h>
using namespace std;

void solve(){
    int a,b,c;
    cin>>a>>b>>c;
    int sum = a+b+c;
    int maxC = max(a,max(b,c));
    cout<<max(0,maxC-(sum-maxC-1))<<'\n';
}

int main(){
#ifndef ONLINE_JUDGE

    //freopen("input.txt", "r", stdin);

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