#include <bits/stdc++.h>
using namespace std;

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
        int n;
        cin>>n;
        string a[n];
        map<string,int> mapple;
        int ans[n];
        memset(ans,0,sizeof(ans));
        mapple[""] = 1;
        for(int i=0;i<n;++i){
            cin>>a[i];
            mapple[a[i]] = 1;
        }
        for(int i=0;i<n;++i){
            for(int j=1;j<a[i].size();++j){
                string pathA = a[i].substr(0,j);
                
                string pathB = a[i].substr(j,a[i].size()-1);
                //cout<<pathA<<" "<<pathB<<"\n";
                if( (mapple[pathA]) && (mapple[pathB])){
                    //cout<<"YES"<<"\n";
                    ans[i] = 1;
                    break;
                }
            }
        }
        for(int i =0;i<n;++i){
            cout<<ans[i]<<"";
        }
        cout<<"\n";
    }
    return 0;
}