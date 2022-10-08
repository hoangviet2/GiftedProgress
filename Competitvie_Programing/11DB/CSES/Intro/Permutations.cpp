// Permutations
#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    if(n==1){
        cout<<1;
        return;
    }
    if(n<4){
        cout<<"NO SOLUTION\n";
        return;
    }
    if(n==4){
        cout<<"2 4 1 3\n";
        return;
    }
    for (int i = 1; i <= n; i += 2) cout << i << " ";
    for (int i = 2; i <= n; i += 2) {
        cout<<i;
        if (i + 2 <= n){
            cout << " ";
        }else{
            cout << "\n";
        }
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