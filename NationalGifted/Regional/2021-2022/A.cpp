#include <bits/stdc++.h>

using namespace std;

#define ll long long
const int N = 1e5 + 5;
ll a[107], cnt, b[100005], res = 1000, sum, ans, n, s;

void backtrack1(ll u)
{
        if (u == (n / 2 + 1))
        {
            cnt++;
            b[cnt] = s;
            return;
        }
        backtrack1(u + 1);
        s = s + a[u];
        backtrack1(u + 1);
        s = s - a[u];
}

void play(ll u)
{
        ll l = 1, h = cnt;
        while (l <= h)
        {
            ll mid = (l + h) / 2;
            if ((sum - 2 * (s + b[mid])) >= 0)
                l = mid + 1;
            else h = mid - 1;
        }
        if ((sum - 2 * (s + b[h])) < 0 || (sum - 2 * (s + b[h])) > res) return;
        if ((sum - 2 * (s + b[h])) < res)
        {
            ans = 0;
            res = sum - 2 * (s + b[h]);
        }
        ans++;
        ll lo = h - 1, hi = h + 1;
        while (lo >= 1 && (sum - 2 * (s + b[lo])) == res)
        {
            ans++;
            lo--;
        }
        while (hi <= cnt && (sum - 2 * (s + b[hi])) == res)
        {
            ans++;
            hi++;
        }
}

void backtrack2(ll u)
{
        if (u == (n + 1))
        {
            play(s);
            return;
        }
        backtrack2(u + 1);
        s = s + a[u];
        backtrack2(u + 1);
        s = s - a[u];
}

int main()
{
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i], sum = sum + a[i];
        backtrack1(1);
        s = 0;
        sort(b + 1, b + cnt + 1);
        backtrack2(n / 2 + 1);
        if (res == 0) ans /= 2;
        cout << res << " " << ans;
}
