#include<bits/stdc++.h>
#define int long long int
#define F first
#define S second
#define pb push_back

using namespace std;

const int N = 1e5+1;
vector<int> grid [N];
int memo[N];
int dp(int node){
    int &ans = memo[node];
    if(ans != -1) return ans;
    ans = 0;
    for(auto x:grid[node]){
        ans = max(ans,dp(x) + 1);
    }
    return ans;

}

int32_t main() {

    int n,m;
    cin>>n>>m;
    for(int i=0;i < m;++i){
        int x,y;
        cin>>x>>y;
        grid[x].push_back(y);
    }
    memset(memo,-1,sizeof(memo));
    int ans = 0;
    for(int i=1;i<=n;++i){
        ans = max(ans,dp(i));
    }
    cout<<ans;
	return 0;
}