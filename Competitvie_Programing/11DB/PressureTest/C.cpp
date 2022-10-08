#include <bits/stdc++.h>

using namespace std;

int main(){
#ifndef ONLINE_JUDGE

    freopen("input.txt", "r", stdin);

    freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
        int n,r;
        cin>>n>>r;
        int a[n];
        for(int i=0;i<n;++i){
            cin>>a[i];
        }
        int ans = 0;
        for(int i=0;i<n;++i){
            if(a[i] == 1){
                int left = 0;
                int right = n;
                if(i-r+1 >= 0){
                    left = i-r+1;
                }
                if(i+r-1<n){
                    right = i-r+1;
                }
                for(int j=left;j<=right;++j){
                    if(a[j] == 0){
                        ++ans;
                        break;
                    }
                }
            }
        }
        cout<<ans+1;
    return 0;
}