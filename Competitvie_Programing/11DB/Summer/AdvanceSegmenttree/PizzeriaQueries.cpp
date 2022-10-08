#include <bits/stdc++.h>
using namespace std;
const int maxN=200007;

int segmenttree1[4*maxN];
int segmenttree2[4*maxN];

void build(vector<int> &a, int node, int left, int right){
    if(left==right){
        segmenttree1[left] = a[left]+left;
        segmenttree2[left] = a[left]-left;
        return;
    }
    int mid = (left+right)/2;
    build(a,2*node,left,mid);
    build(a,2*node+1,mid+1,right);
    segmenttree1[node] = segmenttree1[2*node] + segmenttree1[2*node+1];
    segmenttree2[node] = segmenttree2[2*node] + segmenttree2[2*node+1];
}

int querry(int k){
    
}


void solve(){

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
