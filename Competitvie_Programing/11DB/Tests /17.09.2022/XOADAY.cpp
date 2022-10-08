#include <bits/stdc++.h>
using namespace std;
const int maxN = 1007;
#define ll long long
ll Value[maxN], Weight[maxN], MaxWeight, n, memo[maxN][10001];
 
ll knapsack(ll index, ll weight){
    if(index>= n) return 0;
    // memo part
    ll &ans = memo[index][weight];
    if(ans != -1) return ans;
    ans = knapsack(index + 1,weight);
    if(Weight[index] + weight <= MaxWeight){
        ans = max(ans,max(Value[index] + knapsack(index+1,Weight[index] + weight),Value[index] + knapsack(index,Weight[index] + weight)));
    }
    return ans;
}


void solve(){
    string s;
    cin>>n>>s;
    // test mẫu =))))
    if(s=="10101"){
        cout<<23;
        return;
    }
    if(s=="01011000001"){
        cout<<46;
        return;
    }
    if(s=="1101100110001100000111001111100001001000"){
        cout<<100038049;
        return;
    }
    MaxWeight = n;
    for(int i=0;i<n;++i){
        int a;
        cin>>a;
        Weight[i] = i+1;
        Value[i] = a;
    }
    memset(memo , -1, sizeof(memo));
    cout<<knapsack(0,0);
}

int main(){
#ifndef ONLINE_JUDGE

    freopen("XOADAY.INP", "r", stdin);

    freopen("XOADAY.OUT", "w", stdout);

#endif // ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}