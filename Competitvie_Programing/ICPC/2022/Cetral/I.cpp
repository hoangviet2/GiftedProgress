// abcdef
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MaxN = 100+7;
ll n, d[MaxN];
ll res;

void solve(){
    cin >> n;
    for (int i = 1; i <= n; i++){
        ll a;
        cin >> a;
        d[a%5]++;
    }

    for (int i = 0; i <= 4; i++){
        for (int j = 0; j <= 4; j++){
            for (int z = 0; z <= 4; z++){
                if ((i+j+z) % 5 == 0){
                    if (i == j && j == z){
                        res += d[i]*(d[i]-1)*(d[i]-2);
                    }
                    else if (i == j){
                        res += d[i]*(d[i]-1)*d[z];
                    }
                    else if (j == z){
                        res += d[i]*d[j]*(d[j]-1);
                    }
                    else if (i == z){
                        res += d[i]*(d[i]-1)*d[j];
                    }
                    else{
                        res += d[i]*d[j]*d[z];
                    }
                }
            }
        }
    }
    cout << res/6;
}
int main(){
// #ifndef ONLINE_JUDGE

//     freopen("input.txt", "r", stdin);

//     freopen("output.txt", "w", stdout);

// #endif // ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);
    int t = 1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}