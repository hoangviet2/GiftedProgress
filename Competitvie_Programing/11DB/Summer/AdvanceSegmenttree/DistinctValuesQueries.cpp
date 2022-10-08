#include <bits/stdc++.h>
using namespace std;
void build(int a[], int node, int left, int right){
 
    if(left==right){
        tree[node].value=a[left];
        tree[node].index=left+1;
        return;
    }
    int mid = (left+right)/2;
    build(a,2*node,left,mid);
    build(a,2*node+1,mid+1,right);
    if(tree[2*node].value >= tree[2*node+1].value){
       tree[node]=tree[2*node];
    }
    else{
       tree[node]=tree[2*node+1];
    }
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
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}