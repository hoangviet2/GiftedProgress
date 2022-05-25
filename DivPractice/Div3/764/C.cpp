#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        vector<vector<int>> v(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
            while(arr[i]>0){
                v[i].push_back(arr[i]);
                arr[i]/=2;
            }
        }
        bool used[n]={0};
        bool t=true;
        for(int num=n;num>=1;num--){
            bool cur=false;
            for(int i=0;i<n;i++){
                if(cur)break;
                if(!used[i]){
                    for(int j=0;j<v[i].size();j++){
                        if(v[i][j]==num){
                            cur=1;
                            used[i]=1;
                            break;
                        }
                    }
                }
            }
            if(!cur)t=false;
        }
        if(t)cout<<"YES\n";
        else cout<<"NO\n";
    }
}