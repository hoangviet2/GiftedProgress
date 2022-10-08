#include <bits/stdc++.h>
using namespace std;
#define maxN 100000+7
int nexti[maxN];
void solve(){
    string s;
    while(cin>>s){
        int current, last;
        current = last = 0;
        nexti[0] = 0;
        for(int i=1;i<=s.size();++i){
            if(s[i-1] == '['){
                current = 0;
            }else if(s[i-1]==']'){
                current = last;
            }else {
                nexti[i] = nexti[current];
                nexti[current] = i;
                if(last == current){
                    last = i;
                }
                current = i;
            }
        }
        for(int i=nexti[0];i!=0;i = nexti[i]){
            cout<<s[i-1];
        }
        cout<<"\n";
    }
}
int main(){
#ifndef ONLINE_JUDGE

    freopen("input.txt", "r", stdin);

    freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    t = 1;
    while(t--){
        solve();
    }
    return 0;
}