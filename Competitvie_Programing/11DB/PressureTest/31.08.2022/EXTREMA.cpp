#include <bits/stdc++.h>
using namespace std;
// summaries
struct segmenttree {
    int n;
    vector<int> st;

    void init(int _n) {
        this->n = _n;
        st.resize(4 * n, 0);
    }

    void build(int start, int ending, int node, vector<int> &v) {
        // leaf node base case
        if (start == ending) {
            st[node] = v[start];
            return;
        }

        int mid = (start + ending) / 2;

        // left subtree is (start,mid)
        build(start, mid, 2 * node + 1, v);

        // right subtree is (mid+1,ending)
        build(mid + 1, ending, 2 * node + 2, v);

        st[node] = st[node * 2 + 1] + st[node * 2 + 2];
    }

    int query(int start, int ending, int l, int r, int node) {
        // non overlapping case
        if (start > r || ending < l) {
            return 0;
        }

        // complete overlap
        if (start >= l && ending <= r) {
            return st[node];
        }

        // partial case
        int mid = (start + ending) / 2;

        int q1 = query(start, mid, l, r, 2 * node + 1);
        int q2 = query(mid + 1, ending, l, r, 2 * node + 2);

        return q1 + q2;
    }

    void update(int start, int ending, int node, int index, int value) {
        // base case
        if (start == ending) {
            st[node] = value;
            return;
        }

        int mid = (start + ending) / 2;
        if (index <= mid) {
            // left subtree
            update(start, mid, 2 * node + 1, index, value);
        }
        else {
            // right
            update(mid + 1, ending, 2 * node + 2, index, value);
        }

        st[node] = st[node * 2 + 1] + st[node * 2 + 2];

        return;
    }

    void build(vector<int> &v) {
        build(0, n - 1, 0, v);
    }

    int query(int l, int r) {
        return query(0, n - 1, l, r, 0);
    }

    void update(int x, int y) {
        update(0, n - 1, 0, x, y);
    }
};

void solve(){
    int n,queries;
    cin>>n>>queries;
    segmenttree tree;
    tree.init(n);
    int a[n];
    for(int i=0;i<n;++i){
        cin>>a[i];
    }
    vector<int> based;
    based.push_back(0);
    for(int i=1;i<n-1;++i){
        if(a[i]>a[i-1] && a[i]>a[i+1]){
            based.push_back(1);
        }else if(a[i]<a[i-1] && a[i]<a[i+1]){
            based.push_back(1);
        }else{
            based.push_back(0);
        }
    }
    based.push_back(0);
    tree.build(based);
    while(queries--){
        char ch;
        int x,y;
        cin>>ch>>x>>y;
        if(ch=='T'){
            int preState = tree.query(x-1, x-1);
            int prenum = a[x-1];
            tree.update(x-1,0);
            a[x-1] = y;
            if(a[x-1] > a[x-2] && a[x-1] > a[x]){
                tree.update(x-1, 1);
            }else if(a[x-1] < a[x-2] && a[x-1] < a[x]){
                tree.update(x-1, 1);
            }
            cout<<tree.query(0, n-1)<<"\n";
            tree.update(x-1, preState);
            a[x-1] = prenum;
        }else{
            tree.update(x-1,0);
            a[x-1] = y;
            if(a[x-1] > a[x-2] && a[x-1] > a[x]){
                tree.update(x-1, 1);
            }else if(a[x-1] < a[x-2] && a[x-1] < a[x]){
                tree.update(x-1, 1);
            }
            cout<<tree.query(0, n-1)<<"\n";
        }
    }
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("EXTREMA.INP", "r", stdin);
    freopen("EXTREMA.OUT", "w", stdout);
#endif // ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}