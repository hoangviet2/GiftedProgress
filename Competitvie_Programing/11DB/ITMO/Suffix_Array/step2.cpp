#include <bits/stdc++.h>
#define int long long int
#define F first
#define S second
#define pb push_back
using namespace std;

void count_sort(vector<int> &p, vector<int> &c)
{
    // Sort P by value in c
    int n = p.size();
    // sort for second
    vector<int> cnt(n);
    for (auto x : c)
    {
        cnt[x]++;
    }
    vector<int> p_new(n);
    // counting bucket
    vector<int> pos(n);
    pos[0] = 0;
    for (int i = 1; i < n; ++i)
    {
        pos[i] = pos[i - 1] + cnt[i - 1];
    }
    for (auto x : p)
    {
        int i = c[x];
        p_new[pos[i]] = x;
        pos[i]++;
    }
    p = p_new;
    return;
}

void radix_sort(vector<pair<pair<int, int>, int> > &a)
{
    int n = a.size();
    {
        // sort for second
        vector<int> cnt(n);
        for (auto x : a)
        {
            cnt[x.first.second]++;
        }
        vector<pair<pair<int, int>, int> > a_new(n);
        // counting sort
        vector<int> pos(n);
        pos[0] = 0;
        for (int i = 1; i < n; ++i)
        {
            pos[i] = pos[i - 1] + cnt[i - 1];
        }
        for (auto x : a)
        {
            int i = x.first.second;
            a_new[pos[i]] = x;
            pos[i]++;
        }
        a = a_new;
    }
    // sort for first
    {
        vector<int> cnt(n);
        for (auto x : a)
        {
            cnt[x.first.first]++;
        }
        vector<pair<pair<int, int>, int> > a_new(n);
        vector<int> pos(n);
        pos[0] = 0;
        for (int i = 1; i < n; ++i)
        {
            pos[i] = pos[i - 1] + cnt[i - 1];
        }
        for (auto x : a)
        {
            int i = x.first.first;
            a_new[pos[i]] = x;
            pos[i]++;
        }
        a = a_new;
    }
}

int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    string s;
    cin >> s;
    s += "$";
    int n = s.size();
    vector<int> p(n), c(n);
    // k = 0
    vector<pair<char, int> > a(n);
    for (int i = 0; i < n; ++i)
    {
        a[i] = make_pair(s[i], i);
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n; ++i)
    {
        p[i] = a[i].second;
    }
    c[p[0]] = 0;
    // marking the point
    // mã hoá kí tự. ví dụ a = 1 thì b = 2 từ đó ta có được thứ tự của các kí tự nhưng nó là dạng số
    for (int i = 1; i < n; ++i)
    {
        if (a[i].first == a[i - 1].first)
        {
            c[p[i]] = c[p[i - 1]];
        }
        else
        {
            c[p[i]] = c[p[i - 1]] + 1;
        }
    }

    int k = 0;
    while ((1 << k) < n)
    {
        // which is 2^k < n;
        // k --> k+1

        // vector<pair<pair<int, int>, int> > a(n);
        // for (int i = 0; i < n; ++i)
        // {
        //     a[i] = make_pair(make_pair(c[i], c[(i + (1 << k)) % n]), i);
        // }

        for (int i = 0; i < n; ++i)
        {
            p[i] = (p[i] - (1 << k) + n) % n;
        }

        count_sort(p, c);
        // radix_sort(a);
        vector<int> c_new(n);
        c_new[p[0]] = 0;
        for (int i = 1; i < n; ++i)
        {
            pair<int,int> pre = make_pair(c[p[i-1]] , c[ (p[i-1] + (1<<k)) % n]);
            pair<int,int> now = make_pair(c[p[i]] , c[ (p[i] + (1<<k)) % n]);
            if (now == pre)
            {
                c_new[p[i]] = c_new[p[i - 1]];
            }
            else
            {
                c_new[p[i]] = c_new[p[i - 1]] + 1;
            }
        }
        c = c_new;
        k++;
    }
    for (int i = 0; i < n; ++i)
    {
        //cout << p[i] << " " << s.substr(p[i], n - p[i]) << "\n";
        cout << p[i] << " ";
    }

    return 0;
}