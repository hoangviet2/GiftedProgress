#include <bits/stdc++.h>
using namespace std;

int main(){
#ifndef ONLINE_JUDGE

    //freopen("input.txt", "r", stdin);

    //freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        string s;
        set<char> sets;
        cin>>s;
        for(int i=0;i<n;++i){
            sets.insert(s[i]);
        }
        cout<<n+sets.size()<<"\n";
    }
    return 0;
}