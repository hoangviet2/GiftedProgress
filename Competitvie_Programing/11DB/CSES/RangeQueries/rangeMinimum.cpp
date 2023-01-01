// Static Range Minimum Queries
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxN = 2e5+7;
int a[maxN];
ll seg[4*maxN];
int n;
void build(int l,int r,int id){
    if(l==r){
        seg[id] = a[l];
        return;
    }
    int mid = (l+r)/2;
    build(l,mid,2*id+1);
    build(mid+1,r,2*id+2);
    seg[id] = min(seg[2*id+1],seg[2*id+2]);
}

int query(int start,int end,int l,int r,int id){
    if (start > r || end < l) {
	    return INT_MAX;
    }
    if(start >= l && end <= r){
        return seg[id];
    }
    int mid = (start+end)/2;
    return min(query(start,mid,l,r,id*2+1),query(mid+1,end,l,r,2*id+2));
}

int queriesss(int x,int y){
    return query(0,n-1,x,y,0);
}

void solve(){
    int queries;
    cin>>n>>queries;
    for(int i=0;i<n;++i){
        cin>>a[i];
    }
    build(0,n-1,0);
    while(queries--){
        int x,y;
        cin>>x>>y;
        cout<<queriesss(x-1,y-1)<<"\n";
    }
}

int main(){
// #ifndef ONLINE_JUDGE

//     freopen("input.txt", "r", stdin);

//     freopen("output.txt", "w", stdout);

// #endif // ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);
    int t = 1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}