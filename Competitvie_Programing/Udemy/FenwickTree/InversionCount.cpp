#include <bits/stdc++.h>
using namespace std;

struct Fenwick{
    vector<int> fn;
    int n;
    
    Fenwick(int n){
        init(n);
    }
    
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
    int n;
    cin>>n;
    pair<int,int> a[n];
    for(int i=0;i<n;++i){
        cin>>a[i].first;
        a[i].second = i;
    }
    sort(a,a+n);
    Fenwick tree(n);
    int inversion_count = 0;
    int inversions[n];
    for(int i=0;i<n;++i){
        int element = a[i].first;
        int index = a[i].second;
        inversions[index] = tree.sum(index,n-1);
        inversion_count += inversions[index];
    }
    cout<<inversion_count<<"\n";
}

int main(){
#ifndef ONLINE_JUDGE

    freopen("input.txt", "r", stdin);

    freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    t = 1;
    while(t--){
        solve();
    }
    return 0;
}
