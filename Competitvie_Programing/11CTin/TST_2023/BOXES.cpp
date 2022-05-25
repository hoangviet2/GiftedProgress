// bài 3
#include<bits/stdc++.h>
#define int long long int
#define F first
#define S second
#define pb push_back
using namespace std;

int n;
pair<int, int> a[200007];

void dp(){
    int ans= LLONG_MAX, sum;
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            if(i!=j){
                sum =0;
                if(a[i].first > a[j].first){
                    sum = sum + a[i].first - a[j].first;
                }
                if(a[i].second > a[j].second){
                    sum = sum + a[i].second - a[j].second;
                }
                ans = min(ans, sum);
            }
        }
        cout<<ans<<" ";
        ans = LLONG_MAX;
    }
}
int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("BOXES.INP", "r", stdin);
	freopen("BOXES.OUT", "w", stdout);
#endif
    cin>>n;
    for(int i=0;i<n;++i){
        int x,y;
        cin>>x>>y;
        a[i] = make_pair(x,y);
    }
    dp();
	return 0;
}