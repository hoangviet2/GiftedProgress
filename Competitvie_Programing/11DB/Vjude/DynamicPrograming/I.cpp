#include <bits/stdc++.h>

using namespace std;
int a[1005];
char s[1005];
bool dp[1005][1005];

int main(){
    int n,k;
    while(cin>>n>>k){
        for(int i=1;i<=n;i++)
            cin>>a[i];
        memset(dp,0,sizeof(dp));
        dp[1][a[1]]=1;
        int i,j;
        for(i=2;i<=n;i++)
        {
            int f=0;
            for(j=0;j<=k;j++)
            {
                if(dp[i-1][j])
                {
                    if(j+a[i]<=k) { dp[i][j+a[i]]=1; f=1; }
                    if(j>=a[i])   { dp[i][j-a[i]]=1; f=1; }
                }
            }
            if(f==0) break;
        }
        cout<<i-1<<"\n";

        s[1]='+'; s[i]='\0'; i--;
        for(j=0;j<=k;j++)
        if(dp[i][j]) break;

        for(;i>=2;i--)
        {
            if(j>=a[i]&&dp[i-1][j-a[i]]) { s[i]='+'; j=j-a[i];}
            else { s[i]='-'; j=j+a[i]; }
        }
        puts(s+1);
    }
    return 0;
}