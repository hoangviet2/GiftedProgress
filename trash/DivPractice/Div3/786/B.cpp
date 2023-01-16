#include<bits/stdc++.h>
#define int long long int
#define F first
#define S second
#define pb push_back
using namespace std;
int testCase;
int32_t main() {
    cin>>testCase;
    while(testCase--){
        char a,b;
        cin>>a>>b;
        if(b<a){
            cout<<(a-'a')*25 + (b-'a') + 1<<"\n";
        }else{
            cout<<(a-'a')*25 + (b-'a')<<"\n";
        }
        
    }
	return 0;
}