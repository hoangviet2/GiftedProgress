#include <bits/stdc++.h>

#define endl "\n"

#define int long long

#define pb push_back

#define mp make_pair

#define f1(i, a, b) for (int i = a; i < b; i++)

#define f2(i, a, b) for (int i = a; i > b; i--)

#define ff first

#define ss second

#define lb lower_bound

#define ub upper_bound

#define mod 1000000007

// insert m.insert({ , });

// make_pair( , );

using namespace std;

vector<int> arr[100001];

int vis[100001];

int col[20000];

int cnt;

int cc_size;//for size of connected components.

int maxD;

int max_node;

void dfs(int node)

{

vis[node]=1;

for(int child : arr[node])

{

if(vis[child]==0)

{

dfs(child);

}

}

}

int32_t main(){

 

// for(int i=0;i<n;i++){

// arr[i].clear();

// vis[i]=0;

int n,m,a,b,x;

cin>>n>>m;

for(int i=1;i<=m;i++)

{

cin>>a>>b;

arr[a].pb(b);

arr[b].pb(a);

}

        cin>>x;

vis[x]=1;

for(int i=0;i<n;i++)

        {

 

         if(vis[i]==0)

         {

             dfs(i);

             cnt++;

         }

            


 

        }

        if(cnt==1)

        cout<<"Connected"<<endl;

        else

        cout<<"Not Connected"<<endl;


 

}