// Question link: https://codeforces.com/contest/1611/problem/C
#include <iostream>
#include <vector>
using namespace std;
int a[200005];
void work() {
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	if(n==1) {
		puts("1");
		return;
	}
	if(a[1]!=n&&a[n]!=n) {puts("-1"); return;}
	printf("%d",n);
	if(a[1]==n)
		for(int i=n; i>1; --i) printf(" %d",a[i]);
	if(a[n]==n)
		for(int i=n-1; i; --i) printf(" %d",a[i]);
	putchar('\n');
}
int main() {
	int T=1;
	scanf("%d",&T);
	while(T--) work();
	return 0;
}