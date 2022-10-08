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

    int dfsHelper(int node, bool *visited){
        visited[node] = true;
        int sizes = 1;
        for(auto nbrs:l[node]){
            if(!visited[nbrs]){
                sizes += dfsHelper(nbrs,visited);
            }
        }
        return sizes;
    }

    int spaces(){
        int total = V*(V-1)/2;
        bool *visited = new bool[V];
        memset(visited,0,sizeof(visited));
        for(int i=0;i<V;++i){
            if(!visited[i]){
                int deepth = dfsHelper(i,visited);
                total -= (deepth)*(deepth-1)/2;
            }
        }
        return total;
    }
};

int count_pairs(int n, vector<pair<int,int> > astronauts){
    Graph g(n);
    for(int i=0;i<astronauts.size();++i){
        g.addEdge(astronauts[i].first,astronauts[i].second);
    }
    return g.spaces();
}

int main(){
#ifndef ONLINE_JUDGE

    freopen("input.txt", "r", stdin);

    freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<pair<int,int> > astronauts;
    astronauts.push_back(make_pair(0,1));
    astronauts.push_back(make_pair(2,3));
    astronauts.push_back(make_pair(0,4));
    cout<<count_pairs(5,astronauts);
    return 0;
}