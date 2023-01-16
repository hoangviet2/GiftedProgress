//https://codeforces.com/contest/1611/problem/A
#include <string>
#include <iostream>
#include <vector>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(0);
	int testCase;
	cin>>testCase;
	while(testCase--){
		string s;
		cin>>s;
		vector<int> a(s.size());
		for(int i=0; i<s.size(); i++){
			a[i] = s[i]-'0';
		}
		if(a.back()%2 == 0){
			cout<<0<<'\n';
		}else{
			int ans = -1;
			for(int i=0; i<a.size(); i++){
				if(a[i]%2 == 0){
					ans = 1 + (i!=0);
					break;
				}
			}
			cout<<ans<<'\n';
		}
	}
	return 0;
}