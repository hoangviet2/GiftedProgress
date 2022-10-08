#include <bits/stdc++.h>

using namespace std;
int a,b;
void xuly(int a, int b)
{
    long long c=a*b, cnt=1;
    for(int y=c+1; y<=1000000; ++y)
    {
        long long ans1=1/c - 1/y;
        long long ans2=1/ans2;
        if(1/ans2+1/y==1/c && y!=c*2)
            ++cnt;
    }
    cout<<cnt<<"\n";
}
int main(){
#ifndef ONLINE_JUDGE

    freopen("input.txt", "r", stdin);

    freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
    int t;
    cin>>t;
    while(t--)
    {
        cin>>a>>b;
        xuly(a, b);
    }
    return 0;
}