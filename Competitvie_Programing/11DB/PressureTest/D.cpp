#include <bits/stdc++.h>

using namespace std;
const int N = 5;
int a[N][N];

int dfs(int x,int y){

}

int main(){
#ifndef ONLINE_JUDGE

    freopen("input.txt", "r", stdin);

    freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
    int testcase;
    cin>>testcase;
    for(int i=0;i<5;++i){
            for(int i=0;i<5;++i){
                a[i][j] = 0;
            }
        }
    }
    a[0][0] = 1;
    a[0][1] = 1;
    a[0][2] = 1;
    a[0][4] = 1;
    a[1][1] = 1;
    a[0][3] = 1;
    a[2][4] = 1;
    a[3][1] = 1;
    a[4][0] = 1;
    a[4][2] = 1;
    while(testcase--){
        int x,y;
        cin>>x>>y;
        cout<<dfs(x,y)<<"\n";
    }
    return 0;
}