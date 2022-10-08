#include <bits/stdc++.h>
using namespace std;

void solve(){

}

void getFactorisation(int number, vector<int> &sieve){
	vector<int> factors;
	while(number!=1){
		factors.push_back(sieve[number]);
		number = number/sieve[number];
	}
}

int main(){
#ifndef ONLINE_JUDGE

    freopen("input.txt", "r", stdin);

    freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    t = 1;
    while(t--){
        solve();
    }
    return 0;
}