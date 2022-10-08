// Counting Rooms
#include <bits/stdc++.h>
using namespace std;
int n,m;
bool gr[1007][1007];
int h[] = {1,0,-1,0};
int w[] = {0,1,0,-1};

void dfs(int i,int j){
    // if(i<0||j<0||i>=n||j>=m){
    //     return;
    // }
    // if(gr[i][j]){
    //     gr[i][j] = 0;
    //     for(int x=0;x<4;++x){
    //         dfs(i+h[x],j+w[x]);
    //     }
    // }
    gr[i][j] = 0;
    for(int x=0;x<4;++x){
        int di = i+h[x];
        int dj = j+w[x];
        if(di>=0 && dj>=0 && di<n && dj<m && gr[di][dj]){
            dfs(di,dj);
        }
    }
}

void solve(){
    cin>>n>>m;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            char temp;
            cin>>temp;
            if(temp == '.'){
                gr[i][j] = true;
            }else{
                gr[i][j] = false;
            }
            
        }
    }
    int ans = 0;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(gr[i][j]){
                dfs(i,j);
                ++ans;
            }
        }
    }
    cout<<ans;
}

int main(){
// #ifndef ONLINE_JUDGE

//     freopen("input.txt", "r", stdin);

//     freopen("output.txt", "w", stdout);

// #endif // ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}