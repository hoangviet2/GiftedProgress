//The War With Cockcroaches
#include <bits/stdc++.h>
#define MaxN 200000
#define F first
#define S second
#define pb push_back
#define int long long int

using namespace std;
int n, k;
int a[MaxN+1], Sum = 0;

bool Check(int Mid, int k) {
    int GrSum = 0;
    int GrCnt = 0;
    for (int i=1; i<=n; i++) {
        if (a[i] > Mid)
            return false;
        GrSum += a[i];
        if (GrSum > Mid) {
            GrCnt++;
            GrSum = a[i];
        }
    }
    GrCnt++;
    return (GrCnt <= k);
}

int BinSearchAns() {
    int lo = 1, hi = Sum, mid, ans = -1;
    while (lo <= hi) {
        mid = (lo + hi)/2;
        if (Check(mid, k)) {
            ans = mid;
            hi = mid - 1;
        }
        else
            lo = mid + 1;
    }
    return ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        Sum += a[i];
    }
    cout << BinSearchAns();
    return 0;
}
