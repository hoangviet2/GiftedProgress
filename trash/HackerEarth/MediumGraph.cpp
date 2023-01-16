//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define ll long long

#define pb push_back

#define mod 1000000007

#define vec vector <ll>

#define mp make_pair

#define fo(i,n) for(i=0; i<n; i++)

using namespace std;


 

int main() {

ll i,j,flag=0;

    // your code goes here

    ll n,m;

    cin>>n>>m;

    vec v[n+2];

    bool vis[n+2];

    memset(vis,false,sizeof(vis));

    ll luck[n+2];

    memset(luck,-1,sizeof(luck));

    for(i=0; i<m; i++)

    {

        ll a,b;

        cin>>a>>b;

        v[a].pb(b);

        v[b].pb(a);

    }

    queue <ll> q;

    q.push(0);

    vis[0]=true;

    luck[0]=0;

    while(!q.empty())

    {

        ll p = q.front();

        q.pop();

        for(i=0; i<(ll)v[p].size(); i++)

        {

            if(!vis[v[p][i]])

            {

                vis[v[p][i]]=true;

                luck[v[p][i]]=luck[p]+1;

                q.push(v[p][i]);

            }

        }

    }   

    for(i=1; i<=n-1; i++){
        cout<<luck[i]<<"\n";
    }

    return 0;

}