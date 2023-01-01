// Two Sets
#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	ll n;
    cin >> n;
    ll total = n * (n + 1) / 2;
    if (total & 1)
    {
        cout << "NO";
    }
    else
    {
        cout << "YES" << endl;
        vector<ll> arr1, arr2;
        total /= 2LL;
        while (n)
        {
            if (total - n >= 0)
            {
                arr1.push_back(n);
                total -= n;
            }
            else
            {
                arr2.push_back(n);
            }
            n--;
        }
        cout << arr1.size() << endl;
        for (auto ele : arr1)
            cout << ele << " ";
        cout << endl;
        cout << arr2.size() << endl;
        for (auto ele : arr2)
            cout << ele << " ";
    }
}

int main(){
// #ifndef ONLINE_JUDGE

//     freopen("input.txt", "r", stdin);

//     freopen("output.txt", "w", stdout);

// #endif // ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);
    int t = 1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}