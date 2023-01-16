#include<iostream>
#include <map>
using namespace std;
const int N = 50;
 
int n,a[N];
 
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	int cnt = 1;
	for(int i=2;i<=n;i++)
	{
		if(a[i]==a[i-1]) cnt++;
		else cnt = 1;
		if(cnt >= n/2) 
		{
			cout<<"-1\n";
			return ;
		}
	}
	
	int res = 0;
	for(int i=1;i<=n;i++)
	{
		map<int ,int >mp;
		cnt = 0;
		for(int j=1;j<=n;j++)
		{
			int x = abs(a[j]-a[i]);
			if(a[i]==a[j]) 
			{
				cnt ++ ;
				continue;
			}
			for(int k=1;k*k<=x;k++)
			{
				if(x % k==0)
				{
					if(k*k==x) mp[k]++;
					else mp[x/k]++,mp[k]++;
				}
			}
		}
		for(auto i : mp)
		{
			if(i.second + cnt >= n/2) 
				res = max(res,i.first);
		}
	}
	cout<<res<<'\n';
}
 
int main()
{
	int testcase;
    cin>>testcase;
	while(testcase--)
	{
		solve();
	}
	return 0;
}