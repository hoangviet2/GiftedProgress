#include <bits/stdc++.h>
using namespace std;

void dfs(int current,int par){
    for(auto x:gr[current]){
        if(x!=par){
            dfs(x,current);
        }
    }
}

int main(){
#ifndef ONLINE_JUDGE

    freopen("input.txt", "r", stdin);

    freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    return 0;
}