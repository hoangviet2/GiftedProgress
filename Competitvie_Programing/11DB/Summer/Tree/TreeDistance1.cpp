#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>adj;
vector<int>ans;
 
int bfs(int src,int n) {
    int top;
    queue<int> q;
    vector<int> d(n+1, -1);
    d[src] = 0;
    ans[src] = max(ans[src], d[src]);
    q.push(src);
 
    while(!q.empty()) {
        top = q.front();
        q.pop();
 
        for(int v: adj[top]) {
            if(d[v] == -1) {
                q.push(v);
                d[v] = d[top] + 1;
                ans[v] = max(ans[v], d[v]);
            }
        }
    }
    return top;
}
 

vector<int> treeDistances(){
    int n;
    cin>>n;
    if(n==1){
        return {0};
    }
    ans.assign(n+1,-1);
    adj=vector<vector<int>>(n+1,vector<int>());
    vector<int>value;
    for(int i=0;i<n;++i){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int diam_end_1 = bfs(1,n);
    int diam_end_2 = bfs(diam_end_1,n);
    bfs(diam_end_2,n);
    for(int i=1;i<=n;i++)
    {
        value.push_back(ans[i]);
    }
    return value;
}

void solve(){
    vector<int> ans = treeDistances();
    for(auto element:ans){
        cout<<element<<" ";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    t = 1;
    while(t--){
        solve();
    }
    return 0;
}
