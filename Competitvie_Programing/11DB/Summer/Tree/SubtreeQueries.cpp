#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxN = 200007;

vector<int> g[maxN];

void solve(){
    int n,q;
    cin>>n>>q;
    int x,y;
    for(int i=0;i<n-1;++i){
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
}

int main(){
// #ifndef ONLINE_JUDGE

//     freopen("input.txt", "r", stdin);

//     freopen("output.txt", "w", stdout);

// #endif // ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    t = 1;
    while(t--){
        solve();
    }
    return 0;
}