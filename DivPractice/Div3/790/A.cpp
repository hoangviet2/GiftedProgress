#include<bits/stdc++.h>
#define int long long int
#define F first
#define S second
#define pb push_back
using namespace std;


int32_t main() {

    int t;
    cin>>t;
    while(t--){
        string line;
        cin>>line;
        int first = (line[0]-'0') + (line[1]-'0') + (line[2]-'0');
        int second = (line[3]-'0') + (line[4]-'0') + (line[5]-'0');
        if(first == second){
            cout<<"YES"<<"\n";
        }else{
            cout<<"NO"<<"\n";
        }
    }
	return 0;
}