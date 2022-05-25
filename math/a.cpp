
#include<bits/stdc++.h>
#define int long long int
#define F first
#define S second
#define pb push_back
using namespace std;
int a,b,c,heso;
int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    for(int i=0;i<7;++i){
        cin>>a>>b>>c;
        cin>>heso;
        double NewA=((a/heso)/-2), NewB=((b/heso)/-2), NewC=c/heso;
        // if (((pow(NewA,2))+(pow(NewB,2))-(NewC))>0) {
        //     cout<<"YES"<<endl;
        // }else{
        //     cout<<"NO"<<endl;
        // }
        cout<<heso<<"x^(2)"<<heso<<"y^(2)"<<a<<"x"<<b<<"y"<<c<<"=0"<<"\n";
    }
	return 0;
}