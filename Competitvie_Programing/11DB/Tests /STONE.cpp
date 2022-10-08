#include <bits/stdc++.h>
using namespace std;
int m,n;// m for univers, n for stones
vector<int> stonesInd;
int ans = 0;
void slove(){
    int preInd = 0;
    ans += m-1;
    preInd = stonesInd[n-1];
    for(int i=n-2;i>=0;--i){
        int currentInd = stonesInd[i];
        //cout<<"subtract: "<<preInd-currentInd-1<<"\n";
        ans += preInd-currentInd-1;
        //cout<<"Current: "<<currentInd-1<<"\n";
        ans += currentInd-1;
        preInd = currentInd;
        //ans += (m-preInd);
    }
}
int main(){
    freopen("STONE.INP", "r", stdin);
    freopen("STONE.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //cout<<"Hello world"<<"\n";
    cin>>m>>n;
    for(int i=0;i<n;++i){
        int temp;
        cin>>temp;
        stonesInd.push_back(temp);
    }
    sort(stonesInd.begin(),stonesInd.end());
    slove();
    cout<<ans;
    return 0;
}