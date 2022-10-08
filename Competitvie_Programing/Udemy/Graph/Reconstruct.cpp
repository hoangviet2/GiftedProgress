#include <bits/stdc++.h>
using namespace std;

class node{
public:
    string name;
    list<string> nbrs;
    node(string name){
        this->name = name;
    }
};

class Graph{
    map<string,node*> m;
public:
    Graph(vector<string> cites){
        for(auto city:cites){
            m[city] = new node(city);
        }
    }

    void addEdge(string x,string y,bool undirect = false){
        m[x]->nbrs.push_back(y);
        if(undirect){
            m[y]->nbrs.push_back(x);
        }
    }
    vector<string> DFSHelper(string node,map<string,bool> visited){
        
    }
    vector<string> DFS(string source){
        map<string,bool> visited;
        visited[source] = true;
        vector<string> ans = DFSHelper(source,visited);
        return ans;
    }
};

vector<string> findItinerary(vector<vector<string> > tickets) {
    Graph g(tickets);
    vector<string> ans = g.DFS("JKF");
    return ans;

}

int main(){
#ifndef ONLINE_JUDGE

    freopen("input.txt", "r", stdin);

    freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    return 0;
}