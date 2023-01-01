// 
#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int m,n,s;
    cin>>m>>n>>s;
    vector<pair<int,int> > gr;
    for(int i=0;i<n;++i){
        int a,b;
        cin>>a>>b;
        gr.push_back(make_pair(a,b));
    }
    //cerr<<"HI";
    vector<int> ans (m,-1);
    queue<int> q;
    ans[s] = 0;
    q.push(s);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto x:gr){
            int dest = (node*x.first + x.second)%m;
            if(ans[dest]<0){
                ans[dest] = ans[node] + 1;
                q.push(dest);
            }
        }
    }
    cout<<ans[0]<<'\n';
}
signed main(){
#ifndef ONLINE_JUDGE

    freopen("input.txt", "r", stdin);

    freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);
    int t = 1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}