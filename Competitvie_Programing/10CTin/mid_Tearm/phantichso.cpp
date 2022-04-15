#include<bits/stdc++.h>
#define max 100
using namespace std;

int main(){
    int n;
    cin>>n;
    int F[max][max];
    F[0][0] = 1;
    for(int m = 1; m <= n; m++)
        for (int v = 0; v <= n; v++)
            if(m>v) F[m][v] = F[m-1][v];
            else F[m][v] = F[m-1][v] + F[m][v - m];
    cout << F[n][n];
}