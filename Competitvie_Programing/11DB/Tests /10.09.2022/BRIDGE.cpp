#include <bits/stdc++.h>
using namespace std;

struct car{
    char direction;
    int boardingTime;
    int estimated;
};

void solve(){
    int n,m;
    cin>>n>>m;
    int ans = 0;
    vector<car> bridges;
    car temp;
    for(int i=0;i<n;++i){
        cin>>temp.direction>>temp.boardingTime>>temp.estimated;
        bridges.push_back(temp);
    }
    //char Predir = bridges[0].direction;
    for(int i=0;i<n;++i){
        ans += bridges[i].estimated;
    }
    cout<<ans/ ((n-1)+m);
}

int main(){
// #ifndef ONLINE_JUDGE

//     freopen("BRIDGE.INP", "r", stdin);

//     freopen("BRIDGE.OUT", "w", stdout);

// #endif // ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}