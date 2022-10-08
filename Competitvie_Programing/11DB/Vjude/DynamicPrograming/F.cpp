#include <bits/stdc++.h>

using namespace std;

const int N = 51;

int a[N], dp[N];

int main() {
#ifndef ONLINE_JUDGE

    freopen("input.txt", "r", stdin);

    freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
    int n;
    cin>>n;
    int total = 0;
    for (int i = 0; i < n; i++) {
        cin>>a[i];
        total += a[i];
    }
    dp[n] = 0;
    for (int i = n - 1; i >= 0; i--) {
        dp[i] = abs(a[i] - dp[i + 1]);
    }
    for(int i=0;i<n;++i){
        cout<<dp[i]<<" ";
    }
    cout<<"\n";
    cout<<(total-dp[0])/2<<" "<<(total+dp[0])/2;
    return 0;
}
