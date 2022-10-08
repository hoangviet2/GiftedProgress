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
    ans += bridges[0].estimated;
    char Predir = bridges[0].direction;
    for(int i=1;i<n;++i){
        char dir = bridges[i].direction;
        int beginTime = bridges[i].boardingTime;
        int endTime = bridges[i].estimated;
        if(dir != Predir){
            int diff = beginTime - bridges[i-1].estimated;
            if(diff){
                ans+=diff;
            }
            ans+=endTime;
        }else{
            

        }
        Predir = dir;
    }
}

int main(){
// #ifndef ONLINE_JUDGE

//     freopen("input.txt", "r", stdin);

//     freopen("output.txt", "w", stdout);

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