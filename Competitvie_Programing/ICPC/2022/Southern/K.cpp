#include <bits/stdc++.h>
#define ll long long
#define ii pair <int, int>
#define ill pair <int, ll>
#define llll pair <ll, ll>
#define ld long double
#define el "\n"
#define sp " "
#define modulo (ll)(1e9 + 7)
#define fi first
#define se second
using namespace std;
//const ld y1

ll temp, d, r1, g1, b1, r[20], g[20], b[20];
string ans;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("HTML.INP", "r", stdin);
    //freopen("HTML.OUT", "w", stdout);
    map <int, string> mp;
    r[0] = 255;
    g[0] = 255;
    b[0] = 255;

    r[1] = 192;
    g[1] = 192;
    b[1] = 192;

    r[2] = 128;
    g[2] = 128;
    b[2] = 128;

    r[3] = 0;
    g[3] = 0;
    b[3] = 0;

    r[4] = 255;
    g[4] = 0;
    b[4] = 0;

    r[5] = 128;
    g[5] = 0;
    b[5] = 0;

    r[6] = 255;
    g[6] = 255;
    b[6] = 0;

    r[7] = 128;
    g[7] = 128;
    b[7] = 0;

    r[8] = 0;
    g[8] = 255;
    b[8] = 0;

    r[9] = 0;
    g[9] = 128;
    b[9] = 0;

    r[10] = 0;
    g[10] = 255;
    b[10] = 255;

    r[11] = 0;
    g[11] = 128;
    b[11] = 128;

    r[12] = 0;
    g[12] = 0;
    b[12] = 255;

    r[13] = 0;
    g[13] = 0;
    b[13] = 128;

    r[14] = 255;
    g[14] = 0;
    b[14] = 255;

    r[15] = 128;
    g[15] = 0;
    b[15] = 128;

    mp[0] = "White";
    mp[1] = "Silver";
    mp[2] = "Gray";
    mp[3] = "Black";
    mp[4] = "Red";
    mp[5] = "Maroon";
    mp[6] = "Yellow";
    mp[7] = "Olive";
    mp[8] = "Lime";
    mp[9] = "Green";
    mp[10] = "Aqua";
    mp[11] = "Teal";
    mp[12] = "Blue";
    mp[13] = "Navy";
    mp[14] = "Fuchsia";
    mp[15] = "Purple";

    while (cin >> r1 >> g1 >> b1)
    {
        if (r1 == -1)
        {
            break;
        }
        temp = LLONG_MAX;
        for (int i = 0; i <= 15; i++)
        {
            d = sqrt((r[i] - r1) * (r[i] - r1) + (g[i] - g1) * (g[i] - g1) + (b[i] - b1) * (b[i] - b1));
            if (d < temp)
            {
                temp = d;
                ans = mp[i];
            }
        }
        cout << ans << el;
    }
    return 0;
}
