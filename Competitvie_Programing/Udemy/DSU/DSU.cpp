// DSU find cycle
#include <bits/stdc++.h>
using namespace std;
#define ll long long;
const int maxN = 1e5;
vector<int> parent(maxN,-1);
vector<int> ranks(maxN,1);
vector<pair<int,int> > gr;


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
        ranks[s1] += ranks[s2]+1;
    }
}




void solve(){
    for(int i=0;i<4;++i){
        int a,b;
        cin>>a>>b;
        gr.push_back(make_pair(a,b));
    }
    for(auto x:gr){
        int u,v;
        u = x.first;
        v = x.second;
        int a,b;
        a = find(u);
        b = find(v);
        if(a!=b){
            unions(a,b);
        }else{
            cout<<"FK you";
        }
    }
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