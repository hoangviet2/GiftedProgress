#include <bits/stdc++.h>
using namespace std;
void slove(){
    int n,queries;
    cin>>n>>queries;
    map<int,vector<int> > mapple;
    for(int i=0;i<n;++i){
        int temp;
        cin>>temp;
        mapple[temp].push_back(i);
    }
    for(int i=0;i<queries;++i){
        int a,b;
        cin>>a>>b;
        if(mapple[a].size() == 0 || mapple[b].size() == 0){
            cout<<"NO\n";
        }else if(mapple[a][0] < mapple[b][mapple[b].size()-1]){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }
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
    while (t--){
        slove();
    }
    
    return 0;
}