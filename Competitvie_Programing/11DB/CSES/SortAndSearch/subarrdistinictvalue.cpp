// Subarray Distinct Values
#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> values(n);
    for(int i=0;i<n;++i){
        cin>>values[i];
    }
    ll ans = 0;
    int j = 0;
    map<int,int> mapple;
    for(int i =0;i<n;++i){
        while(j<n && (mapple.size()<k || mapple.count(values[j])>0)){
            mapple[values[j]]++;
            j++;
        }
        ans+=j-i;
        mapple[values[i]]--;
        if(mapple[values[i]] == 0){
            mapple.erase(values[i]);
        }
    }
    cout<<ans;
}

int main(){
#ifndef ONLINE_JUDGE

    freopen("input.txt", "r", stdin);

    freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}