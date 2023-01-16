#include<bits/stdc++.h>
#define int long long int
#define F first
#define S second
#define pb push_back
using namespace std;
int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int testcase;
    cin >> testcase;
 
    while(testcase--){
        int n;
        cin >> n;
        vector <int> p(n);
        for (int i = 0; i < n; i++){
            cin >> p[i];
        }
 
        string s;
        cin >> s;
 
        vector <pair <int, int>> a, b;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0'){
                a.push_back({p[i], i});
            }else{
                b.push_back({p[i], i});
            }
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
 
        vector <int> q(n);
        for (int i = 0; i < a.size(); i++){
            q[a[i].second] = i + 1;
        }
        for (int i = 0; i < b.size(); i++){
            q[b[i].second] = a.size() + i + 1;
        }
        for (int i = 0; i < n; i++){
            cout << q[i] << (i + 1 == n ? '\n' : ' ');
        }
 
    }
	return 0;
}