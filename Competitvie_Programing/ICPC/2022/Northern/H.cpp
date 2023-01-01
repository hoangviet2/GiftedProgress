#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ii pair <int, int>
#define ill pair <int, ll>
#define llll pair <ll, ll>
#define ld long double
#define el "\n"
#define sp " "
#define modulo (ll)(1e9 + 7)
#define ordered_set tree <ll, null_type, less <ll>, rb_tree_tag, tree_order_statistics_node_update>
#define ordered_multiset tree <ll, null_type, less_equal <ll>, rb_tree_tag, tree_order_statistics_node_update>
using namespace std;
using namespace __gnu_pbds;
//const ld y1

ll x, q, k, temp;
string st;
ordered_multiset s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("MEDIAN.INP", "r", stdin);
    //freopen("MEDIAN.OUT", "w", stdout);
    k = 0;
    cin >> q;
    for (int i = 1; i <= q; i++)
    {
        cin >> st;
        if (st == "IN")
        {
            k++;
            cin >> x;
            s.insert(x);
        }
        else if (st == "OUT")
        {
            k--;
            if (k < 0)
            {
                k = 0;
            }
            cin >> x;
            s.erase(s.find_by_order(s.order_of_key(x)));
        }
        else if (st == "MEDIAN")
        {
            if (k % 2 == 1)
            {
                cout << *s.find_by_order(k / 2) << el;
            }
            else if (k % 2 == 0)
            {
                temp = *s.find_by_order(k / 2 - 1) + *s.find_by_order(k / 2);
                if (temp % 2 == 1)
                {
                    cout << temp / 2 << ".5" << el;
                }
                else
                {
                    cout << temp / 2 << el;
                }
            }
        }
        /*for (ll j : s)
        {
            cout << j << sp;
        }
        cout << el;*/
    }
    return 0;
}
