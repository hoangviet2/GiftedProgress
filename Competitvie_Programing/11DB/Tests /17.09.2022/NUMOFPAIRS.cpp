#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1007;
int n;
int a[MAXN], b[MAXN], f[MAXN][MAXN];
vector<int> minVal;
void preprocess(){
    sort(b,b+n);
    for(int i = 0; i < n; ++i){
        if(minVal.size() == 1000){
            return;
        }
        if((minVal.empty() || minVal.back() != b[i] )&& b[i] != 0){
            minVal.push_back(b[i]);
        }
    }
}

void solve(){
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>a[i];
        b[i] = a[i];
    }
    preprocess();
    int curr = 0, maxs = 0;
    vector<int> Lefts;

    for(int i = 0; i < minVal.size(); ++i){
        for(int j = 0; j < n; ++j){
            f[i][j] = a[j] % minVal[i];
            if(f[i][j] == 0){
                ++curr;
            }
            else{

                if(maxs == curr){
                    int x = j-1;
                    while(f[i][x] == 0 && x >= 0)
                    {
                        x--;
                    }
                    Lefts.push_back(x+1);
                }
                if(curr > maxs){
                    Lefts.clear();
                    int x = j-1;
                    while(f[i][x] == 0 && x >= 0)
                    {
                        x--;
                    }
                    Lefts.push_back(x+1);
                }
                maxs = max(maxs, curr);
                curr = 0;
            }
        }
        if(maxs == curr){
            int x = n-2 ;
            while(f[i][x] == 0 && x >= 0){
                x--;
            }
            Lefts.push_back(x+1);
        }
        if(curr > maxs){
            Lefts.clear();
            int x = n-2;
            while(f[i][x] == 0 && x >= 0)
            {
                x--;
            }
            Lefts.push_back(x+1);
        }
        maxs = max(maxs, curr);
        curr = 0;
    }
    sort(Lefts.begin(),Lefts.end());
    cout << Lefts.size()  << " " << maxs-1 << "\n";
    for(int i = 0; i < Lefts.size(); ++i){
        cout << Lefts[i]+1 << " ";
    }
}

int main(){
#ifndef ONLINE_JUDGE

    freopen("NUMOFPAIRS.INP", "r", stdin);

    freopen("NUMOFPAIRS.OUT", "w", stdout);

#endif // ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    while(t--){
        solve();
    }
}
