#include <bits/stdc++.h>
//#include <iostream>
//#include <vector>
using namespace std;

const int N = 1007;
vector<int> mx(N);
vector<int> mn(N);
vector<int> relations(N);

int getrelation(int x) {
    if(x==relations[x]){
        return x;
    }else{
        return relations[x] = getrelation(relations[x]);
    }
}

void slove(int x, int y) {
    x = getrelation(x), y = getrelation(y);
    if (x == y) return;
    relations[x] = y;
    mx[y] = max(mx[y], mx[x]);
    mn[y] = min(mn[y], mn[x]);
}

int main() {
    int n, m;
    cin>>n>>m;
    for (int i = 1; i <= n; i++){
        relations[i] = mx[i] = mn[i] = i;
    }
    while (m--) {
        int l, r;
        cin>>l>>r;
        for (int i = l; i < r; i++){
            slove(i, i + 1);
        }
    }
    int ans = n + 1;
    for (int i = 1; i <= n; i++){
        if (getrelation(i) == i){
            ans += (mx[i] - mn[i]) * 2;
        }
    }
    cout<<ans<<"\n";
}