// Missing Number
#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int> a;
    for(int i = 0;i<n-1;++i){
        int temp;
        cin>>temp;
        a.push_back(temp);
    }
    sort(a.begin(),a.end());
    for(int i=0;i<n;++i){
        if(a[i]!=i+1){
            cout<<i+1;
            return;
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
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}