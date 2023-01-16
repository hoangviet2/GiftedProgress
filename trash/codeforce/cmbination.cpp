#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;
ll res = 0;
void findNumbers(vector<ll>& ar, ll sum,ll i){
	if (sum == 0) {
		++res;
        return;
	}
	while (i < ar.size() && sum - ar[i] >= 0) {
		findNumbers(ar, sum - ar[i], i);
		i++;
	}
}
void combinationSum(vector<ll>& ar,ll sum)
{
	// sort input array
	sort(ar.begin(), ar.end());
	findNumbers(ar, sum, 0);
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
    combinationSum(ar,sum);
    cout<<res;
}
