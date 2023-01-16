// Delay Time in Network
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxN = 1e5;
vector<pair<int,int> > gr[maxN];
void solve(){
    int n,k;
    cin>>n>>k;
    //cout<<n<<" "<<k;
    for(int i=0;i<3;++i){
        int a,b,w;
        cin>>a>>b>>w;
        gr[a].push_back(make_pair(b,w));
    }
    vector<int> dist(n+1,INT_MAX);
    priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;
    dist[k] = 0;
    pq.push(make_pair(0,k));
    while(!pq.empty()){
        pair<int,int> x = pq.top();
        pq.pop();
        for (auto neighbor : gr[x.second]) {
            int ar = dist[x.second] + neighbor.second;
            if (ar < dist[neighbor.first]) {
                dist[neighbor.first] = ar;
                pq.push(make_pair(ar, neighbor.first));
            }
        }
    }
    int max_time = INT_MIN;
    for (int i = 1; i < dist.size(); ++i) {
        if (max_time < dist[i]) {
            max_time = dist[i];
        }
    }
    if(max_time == INT_MAX){
        cout<<-1;
    }else{
        cout<<max_time;
    }
    //cout<<max_time == INT_MAX? -1 : max_time;
}

int main(){
#ifndef ONLINE_JUDGE

    freopen("input.txt", "r", stdin);

    freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);
    int t = 1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}