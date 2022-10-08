#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    string s,t;
    cin>>s>>t;
    int cnt[26];
    memset(cnt,0,sizeof(cnt));
    for(int i=0;i<n;++i){
        cnt[s[i]-'a']++;
        cnt[t[i]-'a']++;
    }
    for(int i=0;i<26;++i){
        if(cnt[i]%2){
            cout<<"NO\n";
            return;
        }
    }
    vector<pair<int,int> > trace;
    cout<<"YES\n";
    for(int i=0;i<n;++i){
        if(s[i] == t[i]){
            continue;
        }
        bool isvalid = false;
        for(int j=i+1;j<n;++j){
            if(s[i] == s[j]){
                swap(t[i],s[j]);
                trace.push_back(make_pair(j+1,i+1));
                isvalid = true;
                break;
            }
        }
        if(!isvalid){
            for(int j=i+1;j<n;++j){
                if(s[i]==t[j]){
                    swap(s[i+1],t[j]);
                    trace.push_back(make_pair(i+2,j+1));
                    swap(s[i+1],t[i]);
                    trace.push_back(make_pair(i+2,i+1));
                    break;
                }
            }
        }
    }
    cout<<trace.size()<<"\n";
    for(auto elem:trace){
        cout<<elem.first<<" "<<elem.second<<"\n";
    }
}

int main(){
#ifndef ONLINE_JUDGE

    //freopen("input.txt", "r", stdin);

    freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}