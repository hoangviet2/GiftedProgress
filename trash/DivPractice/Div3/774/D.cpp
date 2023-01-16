#include<iostream>
#include<algorithm>
#include<math.h>
#include<stdio.h>
#include<cstring>
#include<queue>
using namespace std;
 
const int N = 110;
int arr[N];
int main() {
	int T;
	cin >> T;
	while (T--) {
		int n, t,ans=0,cnt=0;
		cin >> n >> t;
		for (int i = 0;i < n;i++)cin >> arr[i];
		sort(arr, arr + n);
		int c = t;
		while (t--) {
			ans += arr[n -1-c-cnt] / arr[n - 1 - cnt];
			arr[n - 1 - c - cnt] = 0;
			arr[n - 1 - cnt] = 0;
			cnt++;
		}
		for (int i = 0;i < n;i++)ans += arr[i];
		cout << ans << endl;
	}
	return 0;
}