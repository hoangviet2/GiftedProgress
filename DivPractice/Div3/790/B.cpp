#include<bits/stdc++.h>
#define int long long int
#define F first
#define S second
#define pb push_back
using namespace std;


int32_t main() {

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;++i){
            cin>>a[i];
        }
        sort(a,a+n);
        int ans = 0;
        for(int i=1;i<n;++i){
            ans += a[i]-a[0];
        }
        cout<<ans<<"\n";
    }
	return 0;
}