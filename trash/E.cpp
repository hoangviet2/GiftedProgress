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
    cin>>testcase;
    while(testcase--){
        int n , a , b;
        cin>>n>>a>>b;
        vector<int> partleft , partright;
		if((a-1>b) || (n-a+1-(b>a)<n/2) || (b-(a < b)<n/2)){
            cout << -1 << endl; 
            continue;
        }
		for(int i = n ; i ; --i){
			if(i != b && i != a) {
                if(partleft.size() < n / 2 - 1){
                    partleft.push_back(i);
                }else{
                    partright.push_back(i);
                }
            }
			else if(i==b){
                partright.push_back(i);
            }else{
                partleft.push_back(i);
            }
        }
		for(auto t : partleft) cout << t << ' ';
		for(auto t : partright) cout << t << ' ';
		cout << "\n";
    }
	return 0;
}