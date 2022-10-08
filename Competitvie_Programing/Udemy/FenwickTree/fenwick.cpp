#include <bits/stdc++.h>
using namespace std;

struct Fenwick{
    vector<int> fn;
    int n;
    void init(int n){
        this->n = n+1;
        fn.resize(this->n,0);
    }

    void add(int x,int y){
        x++; // 1 based index
        while(x<n){
            fn[x] += y;
            x+= (x&(-x));// last set bit
        }
    }

    int sum(int x){
        x++;
        int ans = 0;
        while(x){
            ans += fn[x];
            x -= (x&(-x));
        }
        return ans;
    }

    int sum(int l,int r){
        return sum(r) - sum(l-1);
    }
};

void solve(){
    vector<int> a = {1,2,3,4,5,6,7};
    Fenwick tree;
    tree.init(a.size());
    for(int i=0;i<a.size();++i){
        tree.add(i,a[i]);
    }
    cout<<tree.sum(0, 4);

}

int main(){
// #ifndef ONLINE_JUDGE

//     freopen("input.txt", "r", stdin);

//     freopen("output.txt", "w", stdout);

// #endif // ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    t = 1;
    while(t--){
        solve();
    }
    return 0;
}
