#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
typedef long long ll;
using namespace std;
vector<ll> a;
vector<ll> b;
ll check(vector<ll>&arr){
    int n = arr.size();
    ll maxp=INT_MIN;
    ll maxn=INT_MIN;
    ll minp=INT_MAX;
    ll minn=INT_MAX;
    for(int i=0;i<n;i++){
        maxp=max(maxp,arr[i]);
        maxn=max(maxn,arr[i]);
        minp=min(minp,arr[i]);
        minn=min(minn,arr[i]);
    }
        
    return max(abs(maxp-minp),abs(maxn-minn));
}
    
ll slove(vector<ll>& arr1, vector<ll>& arr2) {        
    vector<ll>add;
    vector<ll>sub;
    int n = arr1.size();
    for(int i=0;i<n;i++)
        add.push_back(arr1[i]+arr2[i]);
    for(int i=0;i<n;i++)
        sub.push_back(arr1[i]-arr2[i]);    
    return max(check(add),check(sub));
        
}
int main(){
    ll ans = 0;
    int sizes;
    cin>>sizes;
    for(int i=0;i<sizes;++i){
        ll x,y;
        cin>>x>>y;
        a.push_back(x);
        b.push_back(y);
    }
    
    cout<<slove(a,b);
    return 0;
}
