#include<bits/stdc++.h>
#define INP "STR.INP","r",stdin
#define OUT "STR.OUT","w",stdout
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define MAX 101

using namespace std;
string X; // xâu X
string Y; // Xấu Y
int F[MAX][MAX] ={0}; // bảng kế hoạch

void Read(){
    cin>>X>>Y;
}
void Solve(){
    int m = X.length(); //độ dài xâu X
    int n = Y.length(); //độ dài xâu Y
    for(int i=1; i<=m;i++) F[i][0] = i;
    for(int i=1; i<=n;i++) F[0][i] = i;

    for(int i=1; i<=m; i++)
        for(int j=1; j<=n; j++)
            if(X[i-1] == Y[j-1])
                F[i][j] = F[i-1][j-1];                
            else
                F[i][j] = min(F[i][j-1], min(F[i-1][j-1], F[i-1][j])) + 1;

}
void Trace(){
    int m = X.length();
    int n = Y.length();
    cout<<F[m][n]<<"\n";

    while ( m!=0 || n!=0 ){
        if(X[m-1] == Y[n-1]){
            m--;
            n--;
        }else{
            cout<<X<<" -> ";
            if(F[m][n] == F[m][n-1]+1){
                cout << "Insert(" << m <<", "<< Y[n-1] << ")";
                X.insert(X.begin()+m+1, Y[n]);
                n--;
            }
            else{ 
                if(F[m][n] == F[m-1][n-1]+1){
                    cout << "Replace(" << m <<", "<< Y[n-1] << ")";
                    X[m-1] = Y[n-1];
                    n--;
                    m--;
                }
                else{
                    cout<<"Delete(" <<m<< ")";
                    X.erase(m-1,1);
                    m--;
                }
            }
            cout<<"->"<<X<<"\n";
        }
    }
}
int main(){
    freopen(INP);
    freopen(OUT);
    Read();
    Solve();
    Trace();
}