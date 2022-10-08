#include <bits/stdc++.h>
using namespace std;
const int MAXN=200007;
 
struct Node{
  int value;
  int index;
};

Node tree[4*MAXN];
 
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
 
int query(int node, int left, int right, int num){
 
     if(tree[node].value < num)
        return 0;
   
    if(left==right){
 
        tree[node].value = tree[node].value - num;
        return tree[node].index;
    }
 
 
   int mid = (left+right)/2;
 
   if(tree[2*node].value >= num){
      int idx = query(2*node,left,mid,num);
      if(tree[2*node].value >= tree[2*node+1].value){
        tree[node] = tree[2*node];
      }
      else{
        tree[node]=tree[2*node+1];
      }
      return idx;
   }
   else{
      int idx= query(2*node+1,mid+1,right,num);
       if(tree[2*node].value >= tree[2*node+1].value){
         tree[node]=tree[2*node];
      }
      else{
       tree[node]=tree[2*node+1];
      }
 
      return idx;
   }
 
   
 
}

void solve(){
 
    int n,m;
    cin >> n >> m;
    int h[n],r[m];
    for(int i=0;i<n;i++){
        cin >> h[i];
    }
    for(int i=0;i<m;i++){
        cin >> r[i];
    }
    build(h,1,0,n-1);
 
    for(int i=0;i<m;i++){
        cout << query(1,0,n-1,r[i]) << " ";
    }
 
}

int main(){
//#ifndef ONLINE_JUDGE
//
//    freopen("input.txt", "r", stdin);
//
//    freopen("output.txt", "w", stdout);
//
//#endif // ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    t = 1;
    while(t--){
        solve();
    }
    return 0;
}
