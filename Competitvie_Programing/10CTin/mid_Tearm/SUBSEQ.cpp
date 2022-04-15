#include<bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define MaxN 1001
#define MaxK 1001
#define INP "SUBSEQ.INP","r",stdin
#define OUT "SUBSEQ.OUT","w",stdout
using namespace std;

int a[MaxN]={0};
int f[MaxN][MaxK]={0};
int n,k;
void Read(){
    cin>>n>>k;
    for(int i=1; i<=n; i++)
        cin>>a[i];
}
int Sub(int x,int y){
    int t = (x-y) % k;
    if(t>=0) return t;
    else return (t+k); 
}
void Solve(){
    f[0][0] = 0;
    for(int i=1; i<k; i++) f[0][i]=MaxK;

    for(int i=1; i<=n; i++)
        for(int t=0; t<k; t++)
            f[i][t] = min(f[i-1][t], f[i-1][Sub(t,a[i])] + 1);
}

void Trace(){
    int SumAll = 0;
    for(int i=1; i<=n; i++) SumAll += a[i];

    cout<<n-f[n][SumAll % k]<<"\n";
    int i = n, t = SumAll % k;
    int Sum = 0;
    for(int i = n; i>=1; i--){
        if(f[i][t] == f[i-1][t]){
            cout<<"a["<<i<<"] = "<<a[i]<<"\n";
            Sum += a[i];
        }else{
            t = Sub(t,a[i]);
        }
    }
    cout<<"Sum = "<<Sum<<"\n";
}
int main(){
    FAST
    freopen(INP);
    freopen(OUT);
    Read();
    Solve();
    Trace();
}