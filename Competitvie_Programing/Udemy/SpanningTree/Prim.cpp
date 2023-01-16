// Prim algo
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxN = 1e5;
//vector<pair<int,pair<int,int> > > edges;
vector<pair<int,int> > gr[maxN];
vector<int> visited(maxN,0);
int prims(){
    priority_queue< pair<int,int> , vector<pair<int,int> > , greater<pair<int,int> > > WTF;
    
    int ans = 0;
    WTF.push(make_pair(0,1)); // weight/node
    while(!WTF.empty()){
        //cout<<"here";
        auto best = WTF.top();
        WTF.pop();
        int v = best.second;
        int w = best.first;
        if(visited[v]){
            continue;
        }

        ans += w;
        visited[v] = 1;
        for(auto i:gr[v]){
            //cout<<i.first<<"\n";
            if(!visited[i.first]){
                WTF.push(make_pair(i.second,i.first));
            }
        }
    }
    return ans;
}

void solve(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;++i){
        int u,v,w;
        cin>>u>>v>>w;
        //cout<<u<<" "<<v<<" "<<w<<"\n";
        gr[u].push_back(make_pair(v,w));
        gr[v].push_back(make_pair(u,w));
    }
    cout<<prims();
}

int main(){
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