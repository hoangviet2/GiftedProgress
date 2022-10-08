#include <bits/stdc++.h>
#define int long long int
#define F first
#define S second
#define pb push_back
using namespace std;

void generateBracket(string output,int n,int open,int close,int current){
    // base case
    if(current == 2*n){
        cout<<output<<"\n";
        return;
    }

    // open
    if(open<n){
        output += '(';
        generateBracket(output,n,open+1,close,current+1);
        output.pop_back();
    }

    // closing
    if(close<open){
        output += ')';
        generateBracket(output,n,open,close+1,current+1);
        output.pop_back();
    }

}

int32_t main() {
#ifndef ONLINE_JUDGE
	//freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    string output;
    int n;
    cin>>n;
    generateBracket(output,n,0,0,0);
	return 0;
}