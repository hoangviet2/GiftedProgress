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
    void BFS(int source){
        queue<int> q;
        bool *visited = new bool[V];
        memset(visited,0,sizeof(*visited));
        q.push(source);
        visited[source] = 1;
        while(!q.empty()){
            int node = q.front();
            cout<<node<<"\n";
            q.pop();
            for(auto nbrs:l[node]){
                if(!visited[nbrs]){
                    q.push(nbrs);
                    visited[nbrs] = true;
                }
            }
        }
    }

    void dfsHelper(int node, bool *visited){
        visited[node] = true;
        cout<<node<<" , ";
        for(auto nbrs:l[node]){
            if(!visited[nbrs]){
                dfsHelper(nbrs,visited);
            }
        }
        return;
    }

    void DFS(int source){
        bool *visited = new bool[V];
        memset(visited,0,sizeof(*visited));
        dfsHelper(source,visited);
    }
};

int main(){
#ifndef ONLINE_JUDGE

    freopen("input.txt", "r", stdin);

    freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    return 0;
}