#include <iostream>
#include <math.h>
using namespace std;
long long f[31], g[31];
void slove(){
    f[0] = 1;
    f[1] = 0;
    g[0] = 0;
    g[1] = 1;
    for(int i=2;i<31;++i){
        f[i] = f[i-2] + 2*g[i-1];
        g[i] = f[i-1] + g[i-2];
    }
}
int main(){
#ifndef ONLINE_JUDGE

    freopen("input.txt", "r", stdin);

    freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
    int n;
    slove();
    while(cin>>n){
        if(n == -1){
            continue;
        }
        cout<<f[n]<<"\n";
    }
    return 0;
}