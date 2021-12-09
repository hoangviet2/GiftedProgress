#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;
int isvalid(vector<ll> ar, ll sum){
	if (sum == 0) return true;
    ll res = 0;
	for(auto element:ar){
        ll reminder = sum - element;
        if(isvalid(ar,reminder) == true){
            res+=isvalid(ar,reminder);
        }
    }
    return res;
}

// Driver code
int main(){
	vector<ll> ar;
    ll sum,n;
    cin>>sum>>n;
    for(ll i=0;i<n;++i){
        ll temp;
        cin>>temp;
        ar.push_back(temp);
    }
    sort(ar.begin(),ar.end());
    cout<<isvalid(ar,sum);
}
