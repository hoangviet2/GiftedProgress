#include <bits/stdc++.h>

using namespace std;

const int maxn = 5e5+1;
typedef long long ll;
int a[maxn], n;

int binary_Search (ll x)
{
    int l = 1, r = n, res = -1;
    while (l <= r)
    {
        int mid = (l+r)/2;
        if (a[mid] <= x)
        {
            res = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    return res;
}

int main ()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    sort(a+1,a+n+1);
    ll res = 0, can, deu;
    for (int i = 1; i <= n; ++i)
    {
        int j = i + 1;
        ll soluong = 1;
        while (a[j] == a[i] && j <= n)
        {
            ++j;
            ++soluong;
        }
        j--;
        if (soluong < 2) continue;
        deu = ((soluong-1) * (soluong-2) * soluong) / 6;
        can = (soluong * (soluong - 1) / 2) * (binary_Search(2*a[i]-1) - soluong);
        res += deu + can;
        i = j;
    }
    cout << res;
    return 0;
}