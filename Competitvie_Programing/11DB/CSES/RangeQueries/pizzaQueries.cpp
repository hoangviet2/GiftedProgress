// Pizzeria Queries
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxN = 2e5+7;

ll segIn[4*maxN];
ll segOut[4*maxN];
ll a[maxN];
void build(int l,int r,int index){
    if(l==r){
        segIn[index] = a[l]+l;
        return;
    }
    int mid = (l+r)/2;
    build(l,mid,2*index+1);
    build(mid+1,r,2*index+2);
    segIn[index] = min(segIn[2*index+1],segIn[2*index+2]);
}
void buildOUT(int l,int r,int index){
    if(l==r){
        segIn[index] = a[l]-l;
        return;
    }
    int mid = (l+r)/2;
    buildOUT(l,mid,2*index+1);
    buildOUT(mid+1,r,2*index+2);
    segOut[index] = min(segOut[2*index+1],segOut[2*index+2]);
}

void update1(ll l, ll r, ll index, ll val, ll v)
{
    if (r < index || l > index)
        return;
 
    if (l == r)
    {
        segIn[v] = val + l;
        return;
    }
 
    ll mid = (l + r) / 2;
    update1(l, mid, index, val, 2 * v +1);
    update1(mid + 1, r, index, val, 2 * v + 2);
    segIn[v] = min(segIn[2 * v +1], segIn[2 * v + 2]);
}

void update2(ll l, ll r, ll index, ll val, ll v)
{
    if (r < index || l > index)
        return;
 
    if (l == r)
    {
        segOut[v] = val - l;
        return;
    }
 
    ll mid = (l + r) / 2;
    update2(l, mid, index, val, 2 * v +1);
    update2(mid + 1, r, index, val, 2 * v + 2);
    segOut[v] = min(segOut[2 * v +1], segOut[2 * v + 2]);
}

ll query(ll tree[], ll left, ll right, ll x, ll y, ll index)
{
    if (x < left || y > right){
        return LLONG_MAX;
    }
 
    if (x <= left && right <= y){
        return tree[index];
    }
 
    ll mid = (left + right) / 2;
    ll lefts = query(tree, left, mid, x, y, 2 * index+1);
    ll rights = query(tree, mid + 1, right, x, y, 2 * index + 2);
    return min(lefts, rights);
}


void solve(){
    int n,queries;
    cin>>n>>queries;
    for(int i=0;i<n;++i){
        cin>>a[i];
    }
    build(0,n-1,0);
    buildOUT(0,n-1,0);
    while(queries--){
        int x,y,z;
        cin>>x>>y;
        if(x == 1){
            cin>>z;
            update1(0, n - 1, y - 1, z, 1);
            update2(0, n - 1, y - 1, z, 1);
        }else{
            
            ll left = query(segOut, 0, n - 1, 0, y - 1, 1);
            ll right = query(segIn, 0, n - 1, y - 1, n - 1, 1);
            cout << min(left + (y - 1), right - (y - 1)) << "\n";
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