#include<bits/stdc++.h>
#include <iostream>

using namespace std;
int a[200005];
void work() {
	int n,l=1,r=0;
	long long sum;
	cin>>n>>sum;
	for(int i=1; i<=n; ++i)
		cin>>a[i];
	for(int i=1,j=0; i<=n; ++i) {
		if(sum<0) {
			sum-=a[i]; continue;
		}
		while(j<n&&a[j+1]+sum>=0) {
			++j; sum+=a[j];
		}
		if(j-i>r-l) r=j,l=i;
		sum-=a[i];
	}
	if(l<=r) cout<<l<<" "<<r<<"\n";
	else puts("-1");
}
int main() {
	int T=1;
	cin>>T;
	while(T--) work();
	return 0;
}
