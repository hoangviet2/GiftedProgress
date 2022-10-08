#include <bits/stdc++.h>
using namespace std;
int a[10],k;
int helper(int total,int index){
    int ans = 0;
    if(index >= 10 && total!=k){
        return 0;
    }
    if(total == k){
        return 1;
    }
    ans += helper(total,index+1);
    ans += helper(total+a[index],index+1);

    return ans;
}
int slove(){
    int ans = 0;
    ans = helper(0,0);
    return ans;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for(int i=0;i<10;++i){
        cin>>a[i];
    }
    cin>>k;
    cout<<slove();
    return 0;
}