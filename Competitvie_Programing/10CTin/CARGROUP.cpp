#include <bits/stdc++.h>
//#include <iostream>
//#include <vector>
//#include <iomanip>
using namespace std;
const int mx =1000;
const int mR = INT_MAX;
double t[mx+1],f[mx];
int w[mx+1],car[mx+1],n,P,diem=0;
void Readata(){
    int L,v;
    freopen("CARGROUP.INP","r",stdin);
    freopen("CARGROUP.OUT","w",stdout);
    cin>>n>>P>>L;
    for(int i=1; i<=n; i++)
    {
        cin>>w[i]>>v;
        t[i]=L/v;
    }
}
double solve()
{
    int totalW;
    double maxtime;
    f[0]=0;
    for(int i=1; i<=n; i++)
    {
        f[i]=mR; totalW=0;maxtime=0;
        for(int j=i; j>=1; j--)
        {
            totalW = totalW + w[j];
            if(totalW > P) break;
            if(maxtime<t[j]) maxtime = t[j];
            if(f[i]>f[j-1]+maxtime)
            {
                f[i]= f[j-1] + maxtime;
                car[i]=j-1;
            }
        }
    }
    return f[n];
}
int main()
{
    Readata();
    cout<<setprecision(2)<<fixed<<solve()<<"\n";
}

