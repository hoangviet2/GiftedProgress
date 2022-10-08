#include <bits/stdc++.h>
using namespace std;

class Graph{
    int V;
    list<int> *l;
public:
    Graph(int v){
        V = v;
        l = new list<int>[V];
    }
    void addEdge(int i,int j,bool undirect = true){
        l[i].push_back(j);
        if(undirect){
            l[j].push_back(i);
        }
    }
    void print(){
        for(int i=0;i<V;++i){
            cout<<i<<"-->";
            for(auto nodes: l[i]){
                cout<<nodes<<" ";
            }
            cout<<"\n";
        }
    }
    void ShortestPath(int source, int dists = -1){
        queue<int> q;
        bool *visited = new bool[V];
        int *dist = new int[V];
        int *parent = new int[V];
        for(int i=0;i<V;++i){
            visited[i] = 0;
            dist[i] = 0;
            parent[i] = -1;
        }
        q.push(source);
        parent[source] = source;
        dist[source] = 0;
        visited[source] = 1;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto nbrs:l[node]){
                if(!visited[nbrs]){
                    q.push(nbrs);
                    parent[nbrs] = node;
                    dist[nbrs] = dist[node]+1;
                    visited[nbrs] = true;
                }
            }
        }
        // print the min distance
        for(int i=0;i<V;++i){
            cout<<"shortest dist to "<<i<<":"<<dist[i]<<"\n";
        }
        // print the path
        if(dists != -1){
            int temp = dists;
            while(temp!=source){
                cout<<temp<<"-->";
                temp = parent[temp];
            }
            cout<<source<<"\n";
        }
    }
};

int main(){
#ifndef ONLINE_JUDGE

    freopen("input.txt", "r", stdin);

    freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Graph g(7);
    g.addEdge(0,1);
	g.addEdge(1,2);
	g.addEdge(2,3);
	g.addEdge(3,5);
	g.addEdge(5,6);
	g.addEdge(4,5);
	g.addEdge(0,4);
	g.addEdge(3,4);
    g.ShortestPath(1,6);
    return 0;
}