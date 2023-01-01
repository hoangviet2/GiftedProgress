// 
#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    string s;
    cin>>s;
    if(s[0] != 'Y' && s[0] != 's' && s[0]!='e'){
        cout<<"NO\n";
        return;
    }
    int cntOther = 0;
    for(int i=1;i<s.size();++i){
        if(s[i] == 'Y'){
            if(s[i-1] != 's'){
                cout<<"NO\n";
                return;
            }
        }else if(s[i] == 's'){
            if(s[i-1] != 'e'){
                cout<<"NO\n";
                return;
            }
        }else if(s[i] == 'e'){
            if(s[i-1] != 'Y'){
                cout<<"NO\n";
                return;
            }
        }else{
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
}

int main(){
#ifndef ONLINE_JUDGE

    freopen("input.txt", "r", stdin);

    freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);
    int t = 1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}

