#include <bits/stdc++.h>
using namespace std;
const double PI=2.0*acos(0.0);
int main(){
#ifndef ONLINE_JUDGE

    freopen("input.txt", "r", stdin);

    freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    double r,n;
    while(cin>>r>>n){
        cout<<fixed<<setprecision(3)<<r*sin((360.0/n)/180*PI)*r/2*n<<"\n";
    }
    return 0;
}