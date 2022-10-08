#include <bits/stdc++.h>
using namespace std;
#define ll  long long
const int maxN = 107;
const ll maxW = 100000007;
ll value[maxN],volume[maxN],heavy[maxN],maxV;
ll memo[maxN][100001];
int n;
bool cmp(pair<ll,pair<ll, ll> > &a, pair<ll, pair<ll, ll> > b){
    return a.second.second>b.second.second;
}
ll dpFunc(int index,ll currentVolume){
    // base case
    if(index >= n){
        return 0;
    }
    // recursive case
    // do not take
    ll &ans = memo[index][currentVolume];
    if(ans!=-1){
        return ans;
    }
    ans = dpFunc(index+1,currentVolume);
    if(currentVolume+volume[index] <= maxV){
        ans = max(ans,value[index] + dpFunc(index+1,currentVolume+volume[index]));
    }else{
        ll presure = currentVolume+volume[index] - maxV;
        if(heavy[index] >= presure){
            ans = max(ans,value[index] + dpFunc(index+1,currentVolume+volume[index]));
        }
    }
    return ans;
}

void solve(){
    
    cin>>n>>maxV;
    vector<pair<ll,pair<ll,ll> > > stuffs;
    for(int i=0;i<n;++i){
        ll a,b,c;
        cin>>a>>b>>c;
        stuffs.push_back(make_pair(a,make_pair(b,c)));
    }
    sort(stuffs.begin(),stuffs.end(),cmp);
    memset(memo,-1,sizeof(memo));
    for(int i=0;i<n;++i){
        volume[i] = stuffs[i].first;
        value[i] = stuffs[i].second.first;
        heavy[i] = stuffs[i].second.second;
    }

    cout<<dpFunc(0,0);
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    t = 1;
    while(t--){
        solve();
    }
    return 0;
}