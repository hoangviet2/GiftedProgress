// Palindrome Reorder
#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    string s;
    cin>>s;
    map<char,int> m;
    for(int i=0;i<s.size();++i){
        m[s[i]]++;
    }
    int cnt = 0;
    for(auto x:m){
        if(x.second%2){
            ++cnt;
        }
    }
    if(cnt>1){
        cout<<"NO SOLUTION";
    }
    string s;
    for(auto x:m){
        s += string(x.first,)
    }
}

int main(){
// #ifndef ONLINE_JUDGE

//     freopen("input.txt", "r", stdin);

//     freopen("output.txt", "w", stdout);

// #endif // ONLINE_JUDGE
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