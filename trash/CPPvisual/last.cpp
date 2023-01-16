#include <iostream>
#include <queue>
using namespace std;
typedef long long ll;
priority_queue<ll> st;
int main() {
	ll n,target,temp;
	cin>> n>>target;
	for(ll i=0;i<n;i++) {
		cin>>temp;
		st.push(-temp);
	}
	ll ans = 0ll;
	for(ll i=0;i<n-1;i++) {
		ll x = st.top();
		st.pop();
		ll y = st.top();
		st.pop();
		ans += x+y;
		st.push(x+y);
	}
	cout<<-ans;

	return 0;
}