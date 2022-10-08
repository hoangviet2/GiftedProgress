#include <bits/stdc++.h>
using namespace std;

void solve(){
    int temp;
    int n = 0;
    vector<int> a;
    while(cin>>temp){
        a.push_back(temp);
        sort(a.begin(),a.end());
        if(n%2){
            int mid=(0+n)/2;
            int min=mid+1;
            int val=(a[mid]+a[min])/2;
            cout<<val<<"\n";
        }else{
            int mid=(0+n)/2;
            cout<<a[mid]<<"\n";
        }
        ++n;
    }
}

int main(){
#ifndef ONLINE_JUDGE

    freopen("input.txt", "r", stdin);

    freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    t = 1;
    while(t--){
        solve();
    }
    return 0;
}