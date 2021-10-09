#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric> 
using namespace std;
typedef long long ll;
ll n;
ll a[100001];

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;                    
    for (ll i = 1; i <= n; i++)
        cin >> a[i];
    cout << ((accumulate(a + 1, a + 1 + n, 0LL) % 2) ? "NO" : "YES");
}
