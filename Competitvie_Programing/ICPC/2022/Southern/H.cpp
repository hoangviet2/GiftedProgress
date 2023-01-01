#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll maxN=1e9+7;

ll ans;
string l,r;
string secondr;
ll cal(string x)
{
    while(x[0]=='0')
    {
        x.erase(0,1);
    }
    ll res=0;
    res=x[0]-48;
    for(ll i=1;i<x.length();i++)
    {
        res=(res*(x[i]-48))%maxN;
    }
    return res%maxN;
}
string  substract(string x,string y)
{
    string s="";
    while(x.length()>y.length())
    {
        y='0'+y;
    }
    while(x.length()<y.length())
    {
        x='0'+x;
    }
    ll d=0;
    ll numberofstring=x.length()-1;
    for(ll i=numberofstring;i>=0;i--)
    {
        if(x[i]>=y[i]+d)
        {
            s=char(x[i]-y[i]-d+48)+s;
            d=0;
        }
        else
        {
            s=char((10+(x[i]-48)-d-(y[i]-48))+48)+s;
            d=1;
        }
    }
    while(s[0]=='0')
    {
        s.erase(0,1);
    }
    return s;
}
bool check(string x, string y)
{
    if(x.length()>y.length())
    {
        return true;
    }
    else if(x.length()<y.length())
    {
        return false;
    }
    if(x>=y)
    {
        return true;
    }
    return false;
}
int main()
{
ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
//freopen(".inp","r",stdin);
//freopen(".out","w",stdout);
cin>>l>>r;
ll ans=cal(r);
ll ans1=0;
ll p=0;
string a=r;
for(ll i=r.length()-1;i>=1;i--)
{
    if(r[i]!='9')
    {
        p=0;
        r[i]='9';
        p=1;
        while(p==1)
        {
            i--;
            if(r[i]=='0')
            {
                r[i]='9';
                p=1;
            }
            else
            {
                r[i]=char(r[i]-1);
                p=0;
                i++;
            }
        }
    }
    ans=max(ans,cal(r));

}
cout<<ans;
return 0;
}