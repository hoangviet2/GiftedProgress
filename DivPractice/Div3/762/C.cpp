#include <iostream>
using namespace std;
typedef long long ll;
ll t,a,sum,b;

ll rek(ll a,ll sum){
    if(sum){
        ll b;
        ll va=a%10, vs=sum%10;
        a/=10; sum/=10;
        cout<<va<<" "<<vs<<" "<<a<<" "<<sum<<"\n";
        if(vs>=va){
            b=rek(a,sum);
            if(b!=-1){
                b*=10;
                b+=vs-va;
                return b;
            }
        }
        if(sum%10==1 && vs<va && (a<=sum/10)){
            b=rek(a,sum/10);
            if(b!=-1){
                b*=10;
                b+=vs-va+10;
                return b;
            }
        }
        return -1;
    }
    else return 0;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); 
    cout.tie(0); cerr.tie(0);
    cin>>t;
    while(t--){
        cin>>a>>sum;
        b=rek(a,sum);
        cout<<b<<"\n";
    }
}
