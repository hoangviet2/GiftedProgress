#include <bits/stdc++.h>

using namespace std;
bool vis[20][20] ;
char mine[20][20] ;
set< vector< pair<int,int> > > solutions ;
int m1[] = {0 , 0 , -1 , 1};
int m2[] = {-1 , 1 , 0 , 0};
void slove(int n, int r, int c, int limited, vector< pair<int,int> > path)
{
    // is oke to do
    if(r<1||c<1){
        return ;
    }
    else if(r>n||c>n){
        return ;
    }
    if(mine[r][c]=='.' || vis[r][c]==1){
        return ;
    }
    vis[r][c] = 1 ;
    path.push_back(make_pair(r,c)) ;
    // base case
    if(limited==8) // when reach the limited
    {
        sort(path.begin(),path.end()) ;
        solutions.insert(path) ;
        vis[r][c] = 0 ;
        return ;
    }
    // recur case
    for(int i = 0 ; i < 4 ; i++)
    {
        int tempr = r + m1[i];
        int tempc = c + m2[i];
        slove(n,tempr,tempc,limited+1,path);
    }
    // backtracking
    vis[r][c] = 0 ;
}

int main()
{
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif
    int t ;
    cin >> t ;
    while(t--)
    {
        int n ;
        cin >> n ;
        solutions.clear() ;
        // create visited array
        for(int i=0;i<20;i++){
            for(int j=0;j<20;j++){
                vis[i][j] = 0 ;
            }
        }

        // include map
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++)
                cin >> mine[i][j] ;
        }
        // each node of map
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                vector< pair<int,int> > path ;
                slove(n,i,j,1,path) ;
            }
        }
        cout << solutions.size() << "\n" ;
    }
    return 0;
}