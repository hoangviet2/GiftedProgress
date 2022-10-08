#include <bits/stdc++.h>

using namespace std;
struct tree{
    int n;
    vector<int> st;

    void init(int _n){
        this->n = _n;
        st.resize(4 * n,0);
    }

    void build(int start,int ending,int node,vector<int> &v){
        // leaf node
        if(start == ending){
            st[node] = v[start];
            return;
        }
        // build plan: 
        // build from start -> mid
        // build from mid + 1 -> end
        // tạo đến leaf node rồi recursion sẽ tự tạo giá trị
        int mid = (start + ending) / 2;

        // left sub build
        build(start, mid, 2 * node + 1,v);

        // right sub build
        build(mid + 1,ending, 2 * node + 2,v);

        // create node value
        st[node] = st[2 * node + 1] + st[2 * node + 2];
    }

    int query(int start,int ending,int l,int r, int node){
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
    
    void build(vector<int> &v){
        build(0,n-1,0,v);
    }

    int query(int left, int right){
        return query(0,n-1,left,right,0);
    }
};


int main(){
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	vector<int> v (8);
    //cout << v.size();
	for(int i=0;i<8;++i){
		cin>>v[i];
	}

    tree cay;
    cay.init(v.size());
    cay.build(v);
    cay.query(1,4);
    cout<<cay.st[0];

}