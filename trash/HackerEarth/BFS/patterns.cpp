// Question link: https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/practice-problems/algorithm/waves-b18625d7/
#include <vector>
#include <map>
#include <queue>
#include <utility>
#include <iostream>
#define ll long long
#define M 1000000007
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int r, c, ci, cj;

    cin>>r>>c>>ci>>cj;

    vector<int> g[r+1];

    map<pair<int, int>, int> vis;

    queue<pair<int, int> > q;

    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            g[i].push_back(0);

            q.push( make_pair(ci,ci)) ;
        }
    }

    vis[make_pair(ci,ci)] = 1;

    while(!q.empty()){

        pair<int, int> new_co;

        new_co = q.front();

        q.pop();

        int newx = new_co.first;

        int newy = new_co.second;

        for(int i=-1; i<=1; i++){

            for(int j=-1; j<=1; j++){

                if((newx+i<0 || newx+i>=r) || (newy+j<0 || newy+j>=c)){
                    continue;
                }

                if(!vis[ make_pair(newx+i,newy+i) ]){

                    g[newx+i][newy+j] = g[newx][newy] + 1;

                    q.push( make_pair(newx+i,newy+i) );

                    vis[make_pair(newx+i,newy+i)] = 1;

                }

            }

        }
    }
    for(int i=0; i<r; i++){

        for(int j=0; j<c; j++){
            cout<<g[i][j]<<" ";
        }

        cout<<"\n";

    }

}