// CHIANHOM
#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    int n,queries;
    cin>>n>>queries;
    map<int,vector<int> > mapple;
    for(int i=0;i<n;++i){
        int x;
        cin>>x;
        mapple[x%10].push_back(i);
    }
    for(int x = 0;x<queries;++x){
        int left,right;
        cin>>left>>right;
        left--;
        right--;
        for(int i=0;i<10;++i){
            vector<int>::iterator low = lower_bound(mapple[i].begin(),mapple[i].end(),left);
            int lefts = (low - mapple[i].begin());
            if(lefts == mapple[i].size()){
                cout<<0<<" ";
            }else{
                vector<int>::iterator high = upper_bound(mapple[i].begin(),mapple[i].end(),right);
                int rights = (high - mapple[i].begin());
                cout<<abs(lefts-rights)<<" ";
            }
        }
        cout<<"\n";
    }
}

int main(){
#ifndef ONLINE_JUDGE

    freopen("CHIANHOM.INP", "r", stdin);

    freopen("CHIANHOM.OUT", "w", stdout);

#endif // ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}