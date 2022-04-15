#include<bits/stdc++.h>
#define MAX 100
#define INP "Bag.inp","r",stdin
#define OUT "Bag.out","w",stdout
using namespace std;

int n,M,res;
int W[MAX],V[MAX],F[MAX][MAX] = {0};
// W[i] là trọng lượng
// V[i] là trị giá
void Read(){
    cin>>n>>M;
    for(int i=1;i<=n;i++)   
        cin>>W[i]>>V[i];
}
void Solve(){
    for(int i=1; i<=n; i++)
        for(int j=1; j<=M;j++){
            if(j>=W[i])     
                F[i][j] = max(V[i] + F[i-1][j-W[i]], F[i-1][j]);
            else            
                F[i][j] = F[i-1][j];
        }
}
void Trace(){
    cout<<F[n][M]<<"\n";
    while (n!=0){
        if(F[n][M]!=F[n-1][M]){
            cout<<n<<" ";
            M=M-W[n];
        }
        n--;
    }
}
int main(){
    freopen(INP); freopen(OUT);
    Read();
    Solve();
    Trace();
}