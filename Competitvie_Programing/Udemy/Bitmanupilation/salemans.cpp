#include <bits/stdc++.h>
using namespace std;

int tsp(vector<vecotor<int> > dist,int setsofcities, int city,int n){
    // base case
    if(setsofcities == (1<<n) - 1){
        return dist[city][0];
    }

    // try all posible
    int ans = INT_MAX;

    for(int choices=0;choices<n;++choices){
        // check if visited or not
        if(setsofcities&(1<<choices)==0){
            int subprob = dist[city][choices] + tsp(dist,setsofcities|(1<<choices),choices,n);
            ans = min(ans,subprob);
        }
    }
    return ans;
}

int main(){
#ifndef ONLINE_JUDGE

    freopen("input.txt", "r", stdin);

    freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout<<"Hello world"<<"\n";
    return 0;
}