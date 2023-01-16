// https://codeforces.com/group/eK9nrAK5an/contest/355263/problem/B
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int testCase;
    cin>>testCase;
    while(testCase--){
        ll sizes,sum=0;
        cin>>sizes;
        vector<ll> a(sizes);
        for(ll i=0;i<sizes;++i){
            ll temp;
            cin>>temp;
            a[i] = temp;
        }
        sort(a.begin(),a.end());
        ll res=a[0];
        for(ll i=0;i<sizes;i++){
            a[i]-=sum;
            sum+=a[i];
        }
        for(ll i=0;i<sizes;i++){
            res=max(res,a[i]);
        }
        cout<<res<<endl;
    }
    return 0;
}