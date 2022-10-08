#include <bits/stdc++.h>
using namespace std;
// another bảng tập đếm
map<int,int> alphabet;
void check(int num){
    // bảng tập đếm =))))
    map<int,int> m;
    int showmax = 0;
    while(num>0){
        m[num%10]++;
        showmax = max(showmax,m[num%10]);
        num/=10;
    }
    for(auto element:m){
        if(element.second == showmax){
            alphabet[element.first]++;
        }
    }
    
}

void solve(){
    int a,b,n;;
    cin>>a>>b>>n;
    alphabet.clear();
    int x = 1;
    int k = (a*x*x) + (b*x);
    set<int> s;
    while(k<=n){
        s.insert(k);
        ++x;
        k = (a*x*x) + (b*x);
    }
    if(s.empty()){
        cout<<"-1\n";
        return;
    }
    for(auto element:s){
        check(element);
    }
    
    int bigboss = 0;
    int res = 0;
    for(auto element:alphabet){
        if(element.second>bigboss){
            bigboss = element.second;
            res = element.first;
        }
    }
    cout<<res<<"\n";
}

int main(){
//#ifndef ONLINE_JUDGE
//
//    freopen("input.txt", "r", stdin);
//
//    freopen("output.txt", "w", stdout);
//
//#endif // ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
