#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    int cnt = 0;
    int catalan[] = {1, 1, 2, 5, 14, 42, 132, 429, 1430, 4862, 16796, 58786, 208012};
    while(cin>>n){
        if(cnt){
            cout<<'\n';
        }
        cout<<catalan[n]<<'\n';
        ++cnt;
    }
}

int main(){
// #ifndef ONLINE_JUDGE

//     freopen("input.txt", "r", stdin);

//     freopen("output.txt", "w", stdout);

// #endif // ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //cout<<"Hello world"<<"\n";
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}