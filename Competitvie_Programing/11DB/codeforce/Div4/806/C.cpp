#include <bits/stdc++.h>
using namespace std;

int main(){
#ifndef ONLINE_JUDGE

    //freopen("input.txt", "r", stdin);

    //freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;++i){
            cin>>a[i];
        }
        for(int i=0;i<n;++i){
            int steps;
            cin>>steps;
            char command;
            for(int j=0;j<steps;++j){
                cin>>command;
                if(command == 'D'){
                    if(a[i] == 9){
                        a[i] = 0;
                    }else{
                        a[i]++;
                    }
                }else{
                    if(a[i] == 0){
                        a[i] = 9;
                    }else{
                        a[i]--;
                    }
                }
            }
        }
        for(int i=0;i<n;++i){
            cout<<a[i]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}