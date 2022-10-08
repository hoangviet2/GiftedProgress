//
#include <bits/stdc++.h>
using namespace std;
const int maxN = 1e5+7;
vector<int> gr[maxN];
vector<int> roads;
bool cycle;
int out[maxN];
int n,m;
void solve(){
    cin>>n>>m;
    for(int i=0;i<n;++i){
        int a,b;
        cin>>a>>b;
        gr[b].push_back(a);
        out[a]++;

    }
    priority_queue<int> pq;
	for(int i=1,i<=n;++i){
        if (!out[i]){
            pq.push(i);
        }
    }
	while (sz(pq)) {
		int x = pq.top(); 
        pq.pop(); 
        roads.push_back(x);
		for(auto &t:gr[x]) {
			out[t]--;
			if (!out[t]){
                pq.push(t);
            }
		}
	}
	reverse(roads.begin(),roads.end());
	for(auto x:roads){
        cout<<x<<" ";
    }
}

int main(){
#ifndef ONLINE_JUDGE

    freopen("input.txt", "r", stdin);

    freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}