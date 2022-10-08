#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxN = 200007;

vector<int> graph[maxN];
ll dp[maxN];
ll ans[maxN];

void dfsin(int node,int parent,int depth){
    ans[1] += depth;
    dp[node] = 1;
    for (int i : graph[node]){
        if (i != parent) {
            dfsin(i, node, depth + 1);
            dp[node] += dp[i];
        }
    }
}

void dfsout(int node, int parent, int n) {
    for (int i : graph[node]){
        if (i != parent) {
            ans[i] = ans[node] + n - 2 * dp[i];
            dfsout(i, node,n);
        }
    }
}

void solve(){
    int n;
    cin>>n;
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfsin(1, 0, 0);
    dfsout(1,0,n);
    for(int i = 1; i <= n; i++){
        cout<<ans[i]<<" ";
    }
}

int main(){
#ifndef ONLINE_JUDGE

    freopen("input.txt", "r", stdin);

    freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    t = 1;
    while(t--){
        solve();
    }
    return 0;
}
