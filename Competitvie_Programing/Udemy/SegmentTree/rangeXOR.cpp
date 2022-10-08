#include <bits/stdc++.h>

using namespace std;

struct segementtree{
    int n;
    vector<int> st;

    void init(int _n){
        this->n = _n;
        st.resize(4*n,0);
    }
    
    int query(int start, int end,int l,int r,int node){
        if(start > r || end < l){
            return 0;
        }
        if (start >= l && end <= r) {
			return st[node];
		}

        // partial case
		int mid = (start + end) / 2;

		int q1 = query(start, mid, l, r, 2 * node + 1);
		int q2 = query(mid + 1, end, l, r, 2 * node + 2);

		return q1 + q2;
    }

    void build(int start,int end,int node,vector<int> &s){
        if(start==end){
            st[node] = s[node];
            return;
        }

        int mid = (start+end)/2;
        //left
        build(start,mid,2*node+1,s);
        //right
        build(mid+1,end,2*node+2,s);
        st[node] = st[2*node + 1] + st[2*node + 2];
    }

    int query(int l, int r) {
		return query(0, n - 1, l, r, 0);
	}

    void build(vector<int> &s){
        build(0,n-1,0,s);
    }
};

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;++i){
        cin>>a[i];
    }
    segementtree tree;
    tree.init(a.size());
    tree.build(a);
    cin>>n;
    for(int i=0;i<n;++i){
        int x,y;
        cin>>x>>y;
        cout<<tree.query(x-1,y-1)<<"\n";
    }
	return 0;
}