// 
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxN = 1e5;


void printVector(vector<int> v){
    for(auto x:v){
        cout<<x<<" ";
    }
    cout<<"hi";
    return;
}
struct edge{
    int weight;
    int dist;
    edge(int w,int d){
        weight = w;
        dist = d;
    }
};
vector<edge> gr[maxN];
vector<int> shortestPath(vector<vector<int> > roads,int n){
    for(auto x:roads){
        gr[x[0]].push_back(edge(x[1],x[2]));
        gr[x[1]].push_back(edge(x[0],x[2]));
    }
    vector<int> distances(maxN,INT_MAX);
    vector<int> par(maxN,0);
    distances[n] = 0;
    par[n] = 0;
    set<pair<int,int> > s;
    s.insert(make_pair(0,n));
    while(!s.empty()){
        pair<int,int> p = *s.begin();
        s.erase(p);
        for(auto x:gr[p.first]){
            int nbrnode = x.dist;
            int currentEdge = x.weight;
             // the node value
            int tillThisNode = p.first + currentEdge;
            if(tillThisNode<distances[nbrnode]){
                s.erase(make_pair(distances[x.dist],x.dist));
                distances[x.dist]=p.second+x.dist;
				par[x.dist]=p.first;
				s.insert(make_pair(distances[x.dist],x.dist));
            }
        }
    }
    vector<int> path;
	int p=n;
	while(p!=1)	{
		path.push_back(p);
		p=par[p];
	}
	path.push_back(1);
	reverse(path.begin(),path.end());
    cout<<"HI";
    return path;
}

void solve(){
    int n;
    cin>>n;
    vector<vector<int> > roads;
    for(int i=0;i<6;++i){
        vector<int> a(3);
        cin>>a[0]>>a[1]>>a[2];
        roads.push_back(a);
    }
    cout<<"HI";
    vector<int> ans = shortestPath(roads,n);
    printVector(ans);
    return;
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