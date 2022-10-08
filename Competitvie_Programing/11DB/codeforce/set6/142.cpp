#include <bits/stdc++.h>
using namespace std;
set<int> sets;
int main(){
#ifndef ONLINE_JUDGE

    freopen("input.txt", "r", stdin);

    //freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        int temp;
        cin>>temp;
        sets.insert(temp);
    }
    cout<<sets.size();
    return 0;
}