#include <bits/stdc++.h>

using namespace std;

struct node{
    int openBrac;
    int closeBrac;
    int ans;

    node(int answer, int open, int close) {
        ans = answer;
        openBrac = open;
        closeBrac = close;
    }
    node(){
        
    };
};

node operator + (const node& left, const node& right) {
    node res;
    // min(số dấu "(" thừa ra ở cây con trái, và số dấu ")" thừa ra ở cây con phải)
    int tmp = min(left.openBrac, right.closeBrac);

    // Để xây dựng kết quả tối ưu ở nút id, ta nối dãy ngoặc tối ưu ở 2 con, rồi thêm
    // min(số "(" thừa ra ở con trái, số ")" thừa ra ở con phải).
    res.ans = left.ans + right.ans + tmp;

    res.openBrac = left.openBrac + right.openBrac - tmp;
    res.closeBrac = left.closeBrac + right.closeBrac - tmp;

    return res;
}

struct segmenttree
{
    int n;
	vector<node> st;

	void init(int _n) {
		this->n = _n;
		st.resize(4 * n);
	}

    void build(int start, int ending, int nodeind, string &line) {
		// leaf node base case
		if (start == ending) {
			if(line[start] == '('){
                st[nodeind] = node(0,1,0);
            }else{
                st[nodeind] = node(0,0,1);
            }
			return;
		}

		int mid = (start + ending) / 2;

		// left subtree is (start,mid)
		build(start, mid, 2 * nodeind + 1, line);

		// right subtree is (mid+1,ending)
		build(mid + 1, ending, 2 * nodeind + 2, line);

		st[nodeind] = st[nodeind * 2 + 1] + st[nodeind * 2 + 2];
	}

    node query(int start, int ending, int l, int r, int nodeind) {
		// non overlapping case
		if (start > r || ending < l) {
			return node(0,0,0);
		}

		// complete overlap
		if (start >= l && ending <= r) {
			return st[nodeind];
		}

		// partial case
		int mid = (start + ending) / 2;

		node q1 = query(start, mid, l, r, 2 * nodeind + 1);
		node q2 = query(mid + 1, ending, l, r, 2 * nodeind + 2);

		return q1 + q2;
	}

    void build(string &line){
        build(0,n-1,0,line);
    }

    node query(int l,int r){
        return query(0,n-1,l,r,0);
    }

};

int main()
{
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
    string line;
    cin>>line;
    int queries;
    cin>>queries;
    segmenttree tree;
    tree.init(line.size());
    tree.build(line);
    while (queries--){
        int left,right;
        cin>>left>>right;
        cout<<tree.query(left-1,right-1).ans * 2<<"\n";
    }

	return 0;
}