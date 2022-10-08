//Projects
#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<pair<int,int> > schedules;
vector<int> money;
int maxs = INT_MIN;
int dphelper(int index,int curtime){
    if(index>=money.size() || curtime > maxs){
        return 0;
    }
    int ans = 0;
    ans = dphelper(index+1,curtime);
    if(curtime<schedules[index].first){
        ans = max(ans,dphelper(index+1,schedules[index].second)+money[index]);
    }
    return ans;
}

void solve(){
    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        int a,b,c;
        cin>>a>>b>>c;
        schedules.push_back(make_pair(a,b));
        maxs = max(maxs,b);
        money.push_back(c);
    }
    cout<<dphelper(0,0);
}

int main(){
// #ifndef ONLINE_JUDGE

//     freopen("input.txt", "r", stdin);

//     freopen("output.txt", "w", stdout);

// #endif // ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}