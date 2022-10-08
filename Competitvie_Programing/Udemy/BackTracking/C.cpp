// https://codeforces.com/contest/1692/problem/c
#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int testcase;
    cin>>testcase;
    while(testcase--){
        vector<string> a(8);
        string line;
        for(int i=0;i<8;++i){
            cin>>line;
            a.push_back(line);
        }
        for(int i=1;i<7;++i){
            for(int j=1;j<7;++j){
                if(a[i-1][j-1] == '#' && a[i+1][j+1] == '#' && a[i-1][j+1] == '#' && a[i+1][j-1] == '#'){
                    cout<<i<<" "<<j<<"\n";
                }
            }
        }
    }
	return 0;
}

