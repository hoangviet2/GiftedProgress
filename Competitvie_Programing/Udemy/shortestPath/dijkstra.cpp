// basic dijkstra
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5;
struct nodes{
    int weight;
    int destination;
    nodes(int w,int v){
        weight = w;
        destination = v;
    }
};

class Graphs{
private:
    int verticles;
    vector<nodes> gr[N];
public:
    Graphs(int v){
        verticles = v;
    }
    void addEdges(int u,int v,int weight,bool undir = true){
        gr[u].push_back(nodes(weight,v));
        if(undir){
            gr[v].push_back(nodes(weight,u));
        }
    }
    int dijkstra(int src,int dest){
        // data structure
        vector<int> distances(verticles,INT_MAX);
        set<pair<int,int> > s;
        //
        distances[src] = 0;
        s.insert(make_pair(0,src));
        while(!s.empty()){
            auto ref = s.begin();
            int node = ref->second;
            int nodedist = ref->first;
            s.erase(ref);
            for(auto nbr:gr[node]){
                int nbrnode = nbr.destination;
                int currentEdge = nbr.weight;
                // the node value
                int tillThisNode = nodedist + currentEdge;
                if(tillThisNode<distances[nbrnode]){
                    auto this = s.find(make_pair(distances[nbrnode],nbrnode));
                    if(this!=s.end){
                        s.erase(this);
                    }
                    distances[nbrnode] = tillThisNode;
                    s.insert(make_pair(distances[nbrnode],nbrnode));

                }
            }
        }
    }
};

void solve(){

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
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}