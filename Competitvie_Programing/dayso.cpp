#include<bits/stdc++.h>
#define int long long int
#define F first
#define S second
#define pb push_back
using namespace std;
int n;
int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("DAYSO.INP", "r", stdin);
	freopen("DAYSO.OUT", "w", stdout);
#endif
    cin>>n;
    int a[n];
    vector<int> chan,le;
    for(int i=0;i<n;++i){
        cin>>a[i];
        if(a[i]%2 == 0){
            chan.push_back(a[i]);
        }else{
            le.push_back(a[i]);
        }
    }
    for(int i=0;i<chan.size();++i){
        cout<<chan[i]<<" ";
    }
    cout<<"\n";
    for(int i=0;i<le.size();++i){
        cout<<le[i]<<" ";
    }
	return 0;
}