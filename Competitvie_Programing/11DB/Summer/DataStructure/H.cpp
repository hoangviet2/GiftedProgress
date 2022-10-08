#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxN 5007
void solve(){
    int n;
    while(cin>>n){
        if(n==0){
            return;
        }
        priority_queue<int, vector<int>, greater<int> > Q;
        int a[maxN];
        ll ans = 0;
        for(int i=0;i<n;++i){
            cin>>a[i];
        }
        for(int i=0;i<n;++i){
            Q.push(a[i]);
        }
        while(Q.size()>1){
			int a = Q.top();	
            Q.pop();
			int b = Q.top();	
            Q.pop();
			ans += a + b;
			Q.push(a + b);
		}
        cout<<ans<<"\n";
    }
}

int main(){
#ifndef ONLINE_JUDGE

    freopen("input.txt", "r", stdin);

    freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    t = 1;
    while(t--){
        solve();
    }
    return 0;
}