#include <bits/stdc++.h>

using namespace std;

int main(){
// #ifndef ONLINE_JUDGE

//     freopen("input.txt", "r", stdin);

//     freopen("output.txt", "w", stdout);

// #endif // ONLINE_JUDGE
    int testcase;
    cin>>testcase;
    while(testcase--){
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;++i){
            cin>>a[i];
        }
        for(int i=n-1;i>=0;i--){
            if(i + a[i] <= n-1){
                a[i] += a[i+a[i]];
            }
        }
        int maxs = INT_MIN;
        for(int i=0;i<n;++i){
            maxs = max(maxs,a[i]);
        }
        cout<<maxs<<"\n";
    }
    return 0;
}