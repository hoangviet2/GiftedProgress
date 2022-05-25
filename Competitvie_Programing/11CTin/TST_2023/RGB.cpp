// bài 2
#include<bits/stdc++.h>
#define int long long int
#define F first
#define S second
#define pb push_back
using namespace std;

const int maxn = 2001;

int n, c[maxn];
int a[maxn][maxn];
int b[maxn][maxn];
bool dd[maxn][maxn];

void deques(int point, int id, int cost){
    for (int i = 1; i <= n; i++){
        if (a[id][i] != 0 && dd[id][i] == true){
            b[point][i] = min(b[point][i], cost + a[id][i] + c[i]);
            dd[id][i] = false; dd[i][id] = false;
            deques(point, i, cost + a[id][i]);
            dd[id][i] = true; dd[i][id] = true;
        }
    }
}

void dp(){
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            dd[i][j] = true;
            b[i][j] = LLONG_MAX;
        }
        b[i][i] = 0;
    }

    for (int i = 1; i <= n; i++){
        deques(i,i,0);
    }
    for (int i = 1; i <= n; i++){
        int ans = LLONG_MIN;
        for (int j = 1; j <= n; j++)
        {
            ans = max(ans, b[i][j]);
        }
        cout << ans << " ";
    }
}

int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("RGB.INP" ,"r" ,stdin);
    freopen("RGB.OUT" ,"w" ,stdout);
#endif
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> c[i];
    }
    for (int i = 1; i < n; i++){
        int x,y,cost;
        cin >> x >> y >> cost;
        a[x][y] = cost;
        a[y][x] = cost;
    }
    dp();
	return 0;
}