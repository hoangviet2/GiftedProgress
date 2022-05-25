#include<bits/stdc++.h>

#define int long long int
#define ld long double
#define F first
#define S second
#define pb push_back
using namespace std;
const int N = 301;
int n;
ld memo[N][N][N];
ld dp(int zero,int first,int second,int third){
    cout<<"Zero: "<<zero<<", First: "<<first<<", Second: "<<second<<", third: "<<third<<"\n";
    if(first+second+third == 0) return 0;
    ld &ans = memo[first][second][third];
    if(ans!=-1.00){
        return ans;
    }
    ans = n;
    if(first){
        ans+= first*dp(zero+1,first-1,second,third);
    }
    if(second){
        ans+= second*dp(zero,first+1,second-1,third);
    }
    if(third){
        ans+= third*dp(zero,first,second+1,third-1);
    }
    ans/=(ld)(n-zero);
    return ans;
}

int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    cin>>n;
    int a[n];
    int count[4];
    for(int i=0;i<N;++i){
        for(int j=0;j<N;++j){
            for(int z=0;z<N;++z){
                memo[i][j][z] = -1.00;
            }
        }
    }
    memset(count,0,sizeof(count));
    for(int i=0;i<n;++i){
        cin>>a[i];
        count[a[i]]++;
    }
    cout<<setprecision(10)<<fixed;
    cout<<dp(count[0],count[1],count[2],count[3]);
	return 0;
}