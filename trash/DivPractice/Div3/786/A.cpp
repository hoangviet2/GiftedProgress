#include<bits/stdc++.h>
#define int long long int
#define F first
#define S second
#define pb push_back
using namespace std;
int testCase;
int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    cin>>testCase;
    while(testCase--){
        int a,b;
        cin>>a>>b;
        if(b%a != 0){
            cout << 0 << ' ' << 0 << "\n";
        }else{
            cout << 1 << ' ' << b/a << endl;
        }
    }
	return 0;
}