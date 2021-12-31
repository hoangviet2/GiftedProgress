#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;

const int maxn = 200050;

int id [maxn], num [maxn];
int pre [maxn];
char cmd;
long long sum [maxn];
int cnt;
int n, m;

void init () {
     for (int i = 1; i <= n; i ++) {
          id [i] = pre [i] = sum [i] = i;
          num [i] = 1;
          cnt = n;
     }
}

int find (int v) {
    return pre [v] == v? v: find (pre [v]);
}

void join (int a, int b) {
    int fx = find (id [a]), fy = find (id [b]);
      if (fx != fy) {
          pre [fx] = fy;
          num [fy] += num [fx];
          sum [fy] += sum [fx];
      }
}

void Delete (int a) {
      int root = find (id [a]);
      num [root] = num [root] -1;
      sum [root]-= a;
      id [a] = ++ cnt;
      pre [id [a]] = id [a];
      num [id [a]] = 1;
      sum [id [a]] = a;
}

int main () {
    freopen("input.inp","r",stdin);
    while (cin>>n>>m) {
        int p, q;
        init ();
        for (int i = 0; i <m; i ++) {
            cin >> cmd;
            if (cmd == '1'){
                cin >> p >> q;
                if ( find(id [p]) != find(id [q]))
                    join (p, q);
            }
            if (cmd == '2') {
                    cin >> p >> q;
                if (find(id [p]) != find(id[q])) {
                    Delete (p);
                    join (p, q);
                }
            }
            if (cmd == '3') {
                cin >> p;
                cout<<num[find(id[p])]<<" "<<sum[find(id[p])]<<"\n";
            }
        }
    }
     return 0;
}