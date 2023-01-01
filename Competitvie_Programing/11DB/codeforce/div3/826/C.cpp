// Minimize the Thickness
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll maxN = 2e5+7;
ll v[maxN];
ll n;
int ans = INT_MIN;
ll pref[maxN];
int thicks = 0;
int times = 2;
bool isPossilbe(int total,int index){
    int j = 0;
    //cout<<"MOCK: "<<mock<<" ";
    
    //cout<<times<<'\n';
    for(int i=index+1;i<n;++i){
        //cout<<i<<" "<<times*total<<"\n";
        //cout<<pref[i]<<"\n";
        //cout<<thicks<<"\n";
        if(pref[i] == times*total){
            j = i;
            times += 1;
        }
    }
    return ((n-1)==j);
}

void solve(){
    // memset(v,0,sizeof(v));
    // memset(pref,0,sizeof(pref));
    // ans = INT_MIN;
    // thicks = 0;
    cin>>n;
    cin>>v[0];
    pref[0] = v[0];
    for(int i=1;i<n;++i){
        cin>>v[i];
        pref[i] = v[i]+pref[i-1];
    }
    for(int i=0;i<n;++i){
        //cout<<pref[i]<<"\n";
        //cout<<"FK: "<<"\n";
        times = 2;
        if(isPossilbe(pref[i],i)){
            //cout<<times<<"\n";
            if(ans == INT_MIN){
                ans = times;
            }else{
                ans = min(ans,times);
            }
        }
    }
    if(ans == INT_MIN){
        //cout<<"HI"<<"\n";
        cout<<n<<"\n";
        return;
    }
    cout<<ans<<"\n";

}

int main(){
// #ifndef ONLINE_JUDGE

//     freopen("input.txt", "r", stdin);

//     freopen("output.txt", "w", stdout);

// #endif // ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}