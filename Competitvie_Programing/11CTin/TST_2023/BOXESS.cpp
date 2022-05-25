#include<bits/stdc++.h>

using namespace std;

int n;
pair<int, int> a[200007];
void phantu()
{
    cin>>n;
    for(int i=1; i<=n; ++i)
        cin>>a[i].first>>a[i].second;
}
void xuly()
{
    int Min=2000000009, s;
    for(int i=1; i<=n; ++i)
    {
        for(int j=1; j<=n; ++j)
        {
            if(j!=i)
            {
                s=0;
                if(a[i].first>a[j].first)
                    s=s+a[i].first-a[j].first;
                if(a[i].second>a[j].second)
                    s=s+a[i].second-a[j].second;
                Min=min(Min, s);
            }
        }
        cout<<Min<<" ";
        Min=2000000009;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("BOXES.INP" ,"r" ,stdin);
    freopen("BOXES.OUT" ,"w" ,stdout);
    phantu();
    xuly();
    return 0;
}
