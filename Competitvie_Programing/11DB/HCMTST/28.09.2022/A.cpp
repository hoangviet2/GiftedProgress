// FACE
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxN = 1e6;
ll prefixsum[maxN][maxN];
ll getreg(int x0,int y0,int x,int y,int n){
    if(x<0 || y<0 || x>=n || y>=n){
        return 0;
    }
    return prefixsum[x][y];
}

void solve(){
    int queries,n;
    cin>>n>>queries;
    
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            cin>>prefixsum[i][j];
        }
    }
    for(int i=1;i<n;++i){
        prefixsum[0][i] += prefixsum[0][i-1];
    }
    for(int i=1;i<n;++i){
        prefixsum[i][0] += prefixsum[i-1][0];
    }
    for(int i=1;i<n;++i){
        for(int j=1;j<n;++j){
            prefixsum[i][j] += prefixsum[i][j-1] + prefixsum[i-1][j] - prefixsum[i-1][j-1];
        }
    }
    while(queries--){
        int wx1,wy1,wx2,wy2;
        int bx1,by1,bx2,by2;
        cin>>wy1>>wx1>>wy2>>wx2;
        cin>>by1>>bx1>>by2>>bx2;
        ll whiteReg = getreg(0,0,wx2,wy2,n) - getreg(0,0,wx1-1,wy2,n) - getreg(0,0,wx2,wy1-1,n) + getreg(0,0,wx1-1,wy1-1,n);
        ll blackReg = getreg(0,0,bx2,by2,n) - getreg(0,0,bx1-1,by2,n) - getreg(0,0,bx2,by1-1,n) + getreg(0,0,bx1-1,by1-1,n);
        cout<<whiteReg-blackReg<<"\n";
    }
}

int main(){
#ifndef ONLINE_JUDGE

    freopen("input.txt", "r", stdin);

    freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}