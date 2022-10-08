// yêu mà luỵ là dở =))))
#include <bits/stdc++.h>
#define F first
#define S second
#define pb push_back
#define int long long int

using namespace std;
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,queries;
    cin>>n>>queries;
    int a[n];
    for(int i=0;i<n;++i){
        cin>>a[i];
    }
    sort(a,a+n);
    for(int i=1;i<n;++i){
        a[i] += a[i-1];
    }
    for(int i=0;i<queries;++i){
        int avail,extended;
        cin>>avail>>extended;
        if(avail != n){
            cout<<a[n - 1 - (avail-extended)] - a[n-avail-1]<<"\n";
        }else{
            cout<<a[extended-1]<<"\n";
        }
    }
    return 0;
}
