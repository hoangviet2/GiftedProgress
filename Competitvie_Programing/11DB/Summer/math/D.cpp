#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n,m;
    cin>>n>>m;
    vector<int> a(n,0);
    for(int i=0;i<n;++i){
        a[i] = i;
    }
    vector<int> visited(n,0);
    int ans[n];
    vector<int> nextpost(n,0);
    int ind = 0;
    for(int i=0;i<n;i+=2){
        nextpost[i] = ind++;
    }
    for(int i=1;i<n;i+=2){
        nextpost[i] = ind++;
    }
    for(int i=0;i<n;++i){
        if(visited[i] == 0){
            vector<int> cycle;
            int cur = i;
            while (visited[cur] == 0) {
                visited[cur] = 1;
                cycle.push_back(cur);
                cur = nextpost[cur];
            }
            visited[cur] = 1;
            for(int j = 0;j<cycle.size();++j){
                ans[cycle[(j+m)%(cycle.size())]] = cycle[j];
            }

        }
    }
    for(int i=0;i<n;++i){
        cout<<ans[i]+1<<" ";
    }
    cout<<"\n";
}
int main(){
#ifndef ONLINE_JUDGE

    freopen("input.txt", "r", stdin);

    freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}