#include <bits/stdc++.h>
#include <unordered_map>
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
    unordered_map<string,node*> m;
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
};

class GraphBasic{
    int V;
    list<int> *l;
public:
    GraphBasic(int v){
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
    int t;
    t = 1;
    while(t--){
        solve();
    }
    return 0;
}