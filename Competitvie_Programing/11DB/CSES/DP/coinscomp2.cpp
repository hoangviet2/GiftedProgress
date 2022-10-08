#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;
array<int, 1000001> A;
 
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int N, X, c;
    cin >> N >> X;
    A[0] = 1;
    for (int _ = 0; _ < N; _++) {
        cin >> c;
        for (int i = c; i <= X; i++)
            A[i] = (A[i] + A[i - c]) % MOD;
    }
    cout << A[X] << endl;
}