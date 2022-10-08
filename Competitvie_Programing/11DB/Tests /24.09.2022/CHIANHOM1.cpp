#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll maxN=1e9+7;


ll a[10][100020];
ll l,r,q,n,x;
int main()
{
ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
freopen("CHIANHOM.inp","r",stdin);
freopen("CHIANHOM.out","w",stdout);
cin>>n>>q;
for(ll i=1;i<=n;i++)
{
    cin>>x;
    for(ll j=0;j<10;j++)
    {
            if(j==x%10)
            {
                a[j][i]=a[j][i-1]+1;
            }
            else
            {
                a[j][i]=a[j][i-1];
            }
    }
}
for(ll i=1;i<=q;i++)
{
    cin>>l>>r;
    for(ll j=0;j<10;j++)
    {
        cout<<a[j][r]-a[j][l-1]<<" ";
    }
    cout<<"\n";

}
return 0;
}
