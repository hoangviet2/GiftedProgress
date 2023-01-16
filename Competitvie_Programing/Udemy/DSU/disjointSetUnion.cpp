// DSU
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxN = 1e5;
vector<int> WTF(maxN,-1);
list<pair<int,int>> l;

int find(int u){
    if(WTF[u] == -1){
        return u;
    }
    return find(WTF[u]);
}


void unions(int u,int v){
    int s1 = find(u);
    int s2 = find(v);
    if(s1!=s2){
        WTF[s1] = s2;
    }
}

bool check(int u,int v){
    int s1 = find(u);
    int s2 = find(v);
    return s1==s2;
}
vector<bool> DSU(vector<vector<int>>query){
    vector<bool> ans;
    for(auto x:query){
        int a,b,c;
        a = x[0];
        b = x[1];
        c = x[2];
        if(a == 1){
            unions(b,c);
        }else{
            ans.push_back(check(b,c));
        }
    }
    return ans;
}
void solve(){

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