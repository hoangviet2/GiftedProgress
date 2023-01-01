// Dynamic Range Sum Queries
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n,queries;
const int maxN = 2e5+7;
ll a[maxN];
ll seg[4*maxN];
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

ll query(int start,int end,int l,int r,int id){
    if(start > r || end<l){
        return INT_MAX;
    }
    if(start>=l && end<=r){
        return seg[id];
    }
    int mid = (start+end)/2;
    return min(query(start,mid,l,r,2*id+1),query(mid+1,end,l,r,2*id+2));
}

ll query(int l,int r){
    return query(0,n-1,l,r,0);
}

void update(int l,int r,int id,int index,int val){
    if(l==r){
        seg[id] = val;
        return;
    }
    int mid = (l+r)/2;
    if(index<=mid){
        update(l,mid,id*2+1,index,val);
    }else{
        update(mid+1,r,id*2+2,index,val);
    }
    seg[id] = min(seg[2*id+1],seg[2*id+2]);
}

void update(int k,int u){
    update(0,n-1,0,k,u);
    return;
}

void solve(){
    cin>>n>>queries;
    for(int i=0;i<n;++i){
        cin>>a[i];
    }
    build(0,n-1,0);
    while(queries--){
        int c,d,e;
        cin>>c>>d>>e;
        if(c==1){
            update(d-1,e);
        }else{
            cout<<query(d-1,e-1)<<"\n";
        }
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