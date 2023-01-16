// Krushkal
#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct edge{
    int u;
    int v;
    int w;
    edge(int a,int b,int c){
        u = a;
        v = b;
        w = c;
    }
};
bool comp(edge a,edge b){
    return a.w<b.w;
}
vector<edge> l;
const int maxN = 1e5;
vector<int> parent(maxN,-1);
vector<int> ranks(maxN,1);
int find(int u){
    if(parent[u] == -1){
        return u;
    }
    return parent[u] = find(parent[u]);
}

void unions(int u,int v){
    int s1 = find(u);
    int s2 = find(v);
    if(s1!=s2){
        if(s1<s2){
            swap(s1,s2);
        }
        parent[s1] = s2;
        ranks[s1] += ranks[s1];
    }
} 

int Krushkal(){
    int ans = 0;
    sort(l.begin(),l.end(),comp);
    for(auto x:l){
        int s1 = find(x.u);
        int s2 = find(x.v);
        //cout<<s1<<" "<<s2<<"\n";
        if(s1!=s2){
            ans+= x.w;
            unions(x.u,x.v);
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
        l.push_back(edge(u,v,w));
    }
    cout<<Krushkal();
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