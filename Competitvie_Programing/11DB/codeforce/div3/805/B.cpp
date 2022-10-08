#include <bits/stdc++.h>
using namespace std;

void slove(){
    string s;
    cin>>s;
    int n = s.length();
    set<char> sets;
    int ans = 1;
    for (int i = 0; i < n; i++){
        sets.insert(s[i]);
        if (sets.size() == 4){
            ans++;
            sets.clear();
        }
        sets.insert(s[i]);
    }
    cout<<ans<<"\n";
}

int main(){
#ifndef ONLINE_JUDGE

    freopen("input.txt", "r", stdin);

    freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
    int t;
    cin >> t;
    while (t--){
        slove();
    }
}