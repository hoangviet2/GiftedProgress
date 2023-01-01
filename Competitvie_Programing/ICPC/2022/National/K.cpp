#include<bits/stdc++.h>
#define ll long long
using namespace std;
 
bool prime(int n) {
    for(int i=2; i<=sqrt(n); i++) 
	{
        if(n%i==0) return false;
    }
    return true;
}
 
int main() {
    int t,d;
    cin>>t;
    while(t--) {
        cin>>d;
        int now=1;
        ll a=0,b=0;
        while(true) {
            for(int i=now+d; ; i++) {
                if(prime(i)) {
                    if(a) {
                        b=i;
                        break;
                    }
                    else {
                        a=i;
                        now = i;
                        break;
                    }
                }
            }
            if(b!=0) break;
        }
        cout<<a*b<<endl;
    }
    return 0;
}