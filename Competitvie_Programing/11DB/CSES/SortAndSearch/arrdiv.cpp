// Array Division
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll maxN = 2e5+7;
ll v[maxN];
ll n,k,hi=0,cnt;
ll low=9e18;

bool check(ll total){
    ll temp=0,cnt = 1;
	for(ll i=0;i<n;++i){
		if(v[i]>total){
            return false;
        }
		if(v[i]+temp<=total){
            temp+=v[i];
		}else {
			temp=v[i];
            cnt++;
		}
	}
	
	return cnt<=k;
}

void solve(){
    cin>>n>>k;
    for(int i=0;i<n;++i){
        cin>>v[i];
        hi += v[i];
        low = min(low,v[i]);
    }
    ll ans = -1;
    while(hi>=low){
        ll mid=(low+hi)/2;
		if(check(mid)){
			ans=mid;
			hi=mid-1;
		}else{
			low=mid+1;
		}
    }
    cout<<ans<<"\n";

}

int main(){
#ifndef ONLINE_JUDGE

    freopen("input.txt", "r", stdin);

    freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}