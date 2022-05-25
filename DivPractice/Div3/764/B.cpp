#include <algorithm>
#include <iostream>
using namespace std;
bool check(int a, int b) {
	return a >= b && a % b == 0;
}
int main(){
    int testcase;
    cin>>testcase;
    while(testcase--){
        int a, b, c; cin >> a >> b >> c;
        // 10 5 30 (this for the case b is the num)
		if ((a + c) % 2 == 0 && check((a + c) / 2, b)) {
			cout << "YES\n";
			continue;
		}
		if (check(b + b - a, c)) {
			cout << "YES\n";
            cout<<"2b case: "<<a<<" "<<b<<" "<<c<<"\n";
			continue;
		}
		if (check(b - (c - b), a)) {
			cout << "YES\n";
            cout<<"unknow case: "<<a<<" "<<b<<" "<<c<<"\n";
			continue;
		}
		cout << "NO\n";
    }
    return 0;
}