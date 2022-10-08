#include <bits/stdc++.h>
#define int long long int
#define F first
#define S second
#define pb push_back
using namespace std;

void findSubset(string input,string output,int i){
	//base case
	if(input[i] == ' '){
		cout<<output<<"\n";
		return;
	}
	// rec case
	// exclude ith letter
	findSubset(input,output,i+1);
	// include ith letter
	output += input[i];
	findSubset(input,output,i+1);
}

int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	string inputs;
	string outputs;
	cin>>inputs;
	inputs += ' ';
	findSubset(inputs,outputs,0);
	return 0;
}