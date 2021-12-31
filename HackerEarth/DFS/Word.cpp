//question link: https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/practice-problems/algorithm/words-and-trees-f9ef202c/
#include<bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;
struct node{

    vector<int>child;

    int arr[26] = {};

};

vector<node>tree;

vector<char>label;

vector<bool>vis;


 

void addEdge(int u,int v)

{

    tree[u].child.push_back(v);

    tree[v].child.push_back(u);

}


 

void dfs(int u, int par = -1)

{

    tree[u].arr[label[u]-'a'] += 1;

    vis[u] = 1;

    for(int v : tree[u].child)

    {

        if(v == par) continue;

        if(!vis[v])

            dfs(v,u);

        for(int i = 0;i < 26;i += 1)

            tree[u].arr[i] += tree[v].arr[i];

    }

}


 

void runCase_()

{

    int n,q; cin >> n >> q;

    tree.resize(n);

    label.resize(n);

    vis.assign(n,false);

    for(char &c : label) cin >> c;

    for(int i = 1; i < n; ++i)

    {

        int u,v; cin >> u >> v;

        --u, --v;

        addEdge(u,v);

    }

    dfs(0);

    while(q--)

    {

        int arr[26] = {}, x;

        cin >> x; --x;

        string s; cin >> s;

        for(char c : s) arr[c-'a'] += 1;

        int ans = 0;

        for(int i = 0;i < 26; i += 1)

        {

            if(tree[x].arr[i] < arr[i])

                ans += (arr[i] - tree[x].arr[i]);

        }

        cout << ans << endl;

    }

}


 

int main()

{

    runCase_();

    return 0;

}