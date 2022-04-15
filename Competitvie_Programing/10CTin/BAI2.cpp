#include <bits/stdc++.h>
#include <alog>
using namespace std;
#define ll long long
ll n,a[5005],res,tmp,i,j;
void solve()
{
    freopen("BAI2.inp","r",stdin);
    freopen("BAI2.out","w",stdout);
    cin>>n;
    for( i=0; i<n;i++)cin>>a[i];
    sort(a,a+n);
    for( i=0; i<n-2; i++)
    {
        for(ll j=i+1; j<n-1; j++)
        {
            tmp = lower_bound(a+j+1, a+n, a[i]+a[j])-a;
            res=res+(tmp-j-1);
        }
    }
    cout<<res;
}
int main()
{
    solve();
}