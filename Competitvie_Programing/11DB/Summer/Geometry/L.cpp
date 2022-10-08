#include <bits/stdc++.h>
using namespace std;

void solve(){
    double width;
    cin>>width;
    double height = width*6/10;
    double r = width/5;
    double area = (r*r)*M_PI;
    cout<<setprecision(2)<<fixed<<area<<" "<<(width*height)-area<<"\n";
}

int main(){
#ifndef ONLINE_JUDGE

    freopen("input.txt", "r", stdin);

    freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}