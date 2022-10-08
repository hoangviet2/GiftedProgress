#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+7;
int n, k, a[N], prefixSum[N], mins[N];

bool check(int mid) {
    for (int i = 1; i <= n; i++) {
        int temp = (a[i] > mid) ? 1 : -1;
        prefixSum[i] = prefixSum[i-1] + temp;
        mins[i] = min(mins[i-1], prefixSum[i]);
    }
    for (int i = k; i <= n; i++){
        if (prefixSum[i] > mins[i-k]){
            return true;
        }
    }
    return false;
}

int main() {
#ifndef ONLINE_JUDGE

    //freopen("input.txt", "r", stdin);

    freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> k;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    int L = 1, R = n+1;
    while(L < R) {
        int mid = (L+R)/2;
        if (check(mid)){
            L = mid + 1;
        }
        else{
            R = mid;
        }
    }
    cout << L;
    return 0;
}
