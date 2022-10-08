#include <bits/stdc++.h>
using namespace std;
int main(){
#ifndef ONLINE_JUDGE

    //freopen("input.txt", "r", stdin);

    freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int n = s.size();
        int ans[n+1];
        memset(ans,0,sizeof(ans));
        for(int i=0;i<n;++i){
            ans[i+1] = ans[i];
            if(s[i] == '[' || s[i] == ']'){
                if(i%2){
                    ans[i+1]++;
                }else{
                    ans[i+1]--;
                }
            }
        }
        // for(int i=0;i<n;++i){
        //     cout<<ans[i]<<" ";
        // }
        int q;
        cin>>q;
        while (q--){
            int a,b;
            cin>>a>>b;
            //cout<<ans[a-1]<<" "<<ans[b]<<"\n";
            cout<<abs(ans[a-1] - ans[b])<<"\n";
        }
        
    }
}