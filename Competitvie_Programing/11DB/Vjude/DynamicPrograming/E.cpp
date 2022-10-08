#include<bits/stdc++.h>
using namespace std;
int main(){
// #ifndef ONLINE_JUDGE

//     freopen("input.txt", "r", stdin);

//     freopen("output.txt", "w", stdout);

// #endif // ONLINE_JUDGE
    int testcase;
    cin>>testcase;
    while(testcase--){
        int n,k;
        cin>>n>>k;
        int p[k+1];
        for(int i=1; i<=k; i++ ){
            cin>>p[i];
        }
        int ans[k+1];
        for(int i=1; i<=k; i++){
            ans[i] = p[i];
        }
        for(int i=2; i<=k; i++){
            for(int j=1; j<i; j++){
                if(p[i-j] == -1  || ans[j] == -1){
                    continue;
                }
                if(ans[i] == -1){
                    ans[i] = ans[j] + p[i-j];
                }else{
                    ans[i] = min(ans[i], ans[j] + p[i-j]);
                }
            }

        }
        if(k==0){
            cout<<0<<"\n";
        }else{
            cout<<ans[k]<<"\n";
        }
    }
    return 0;
}