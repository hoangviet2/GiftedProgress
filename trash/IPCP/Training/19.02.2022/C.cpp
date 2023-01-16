//#include<bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int testCase;
    cin >> testCase;

    while (testCase--) {
        int n;
        cin >> n;
        vector<ll> a(n);
        for (int i=0;i<n;++i){
            cin >> a[i];
        }
        int prev = -1;
        bool ok = 1;
        for (int i = 0; i < n; i++) {
            if (a[i] <= prev) {
                ok = 0;
                break;
            }
            if (i != n - 1){
                a[i + 1] += a[i] - prev - 1;
            }
            prev = prev + 1;
        }
        cout << (ok ? "YES\n" : "NO\n");
    }

    return 0;
}
