// knapsack
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2007;

ll Value[N], Weight[N], MaxWeight, n, memo[N][10001];
 
ll knapsack(int index, int weight){
    if(index>= n) return 0;
    // memo part
    ll &ans = memo[index][weight];
    if(ans != -1) return ans;
    ans = knapsack(index + 1,weight);
    if(Weight[index] + weight <= MaxWeight){
        ans = max(ans,Value[index] + knapsack(index+1,Weight[index] + weight));
    }
    return ans;
}

int main(){
// #ifndef ONLINE_JUDGE
// 	freopen("CAYKHE.INP", "r", stdin);
// 	freopen("CAYKHE.OUT", "w", stdout);
// #endif
    cin>>MaxWeight>>n;
    for(int i=0;i<n;++i){
        int a,b;
        cin>>a>>b;
        Weight[i] = a;
        Value[i] = b;
    }
    memset(memo , -1, sizeof(memo));
    cout<<knapsack(0,0);
	return 0;
}
