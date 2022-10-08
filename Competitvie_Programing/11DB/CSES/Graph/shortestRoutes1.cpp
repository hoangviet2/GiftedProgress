//Shortest Routes I
#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int maxN = 1e5+7;
ll distances[maxN];
struct edge{
    int destination;
    ll weight;
    edge(int dest,ll w){
        destination = dest;
        weight = w;
    }
};

struct node{
    int id;
    ll dist;
    friend bool operator<(const node &a, const node &b){
        return a.dist > b.dist;
    }
    node(int ids,ll distance){
        id = ids;
        dist = distance;
    }
};

vector<edge> gr[maxN];
priority_queue<node> Q;

//ll dis[maxN][maxN];

void solve(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;++i){
        int a,b;
        ll c;
        cin>>a>>b>>c;
        gr[a].push_back(edge(b,c));
        //dis[a][b] = min(dis[a][b],c);
        
    }
    memset(distances,0x3f,sizeof(distances));
    distances[1] = 0;
    Q.push(node(1,0));
    while(!Q.empty()){
        ll curdist = Q.top().dist;
        int curnode = Q.top().id;
        Q.pop();
        if(distances[curnode] < curdist){
            continue; 
        }
        for(edge x:gr[curnode]){
            if(curdist+x.weight < distances[x.destination]){
                distances[x.destination] = curdist+x.weight;
                Q.push(node(x.destination,curdist+x.weight));
            }
        }
    }
    for(int i=1;i<=n;++i){
        cout<<distances[i]<<" ";
    }
}

int main(){
// #ifndef ONLINE_JUDGE

//     freopen("input.txt", "r", stdin);

//     freopen("output.txt", "w", stdout);

// #endif // ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}