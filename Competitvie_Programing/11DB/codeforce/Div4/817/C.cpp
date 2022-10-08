#include <bits/stdc++.h>
using namespace std;

void solve(){
    map<string,int> mapple;
    int n;
    cin>>n;
    string s;
    vector<string> one,two,three;
    int onea = 0;
    int twoa = 0;
    int threea = 0;
    for(int i=0;i<n;++i){
        cin>>s;
        mapple[s]++;
        one.push_back(s);
    }
    for(int i=0;i<n;++i){
        cin>>s;
        mapple[s]++;
        two.push_back(s);
    }
    for(int i=0;i<n;++i){
        cin>>s;
        mapple[s]++;
        three.push_back(s);
    }

    for(auto element:one){
        if(mapple[element] == 1){
            onea += 3;
        }else if(mapple[element] == 2){
            onea += 1;
        }
    }
    for(auto element:two){
        if(mapple[element] == 1){
            twoa += 3;
        }else if(mapple[element] == 2){
            twoa += 1;
        }
    }
    for(auto element:three){
        if(mapple[element] == 1){
            threea += 3;
        }else if(mapple[element] == 2){
            threea += 1;
        }
    }
    cout<<onea<<" "<<twoa<<" "<<threea<<"\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    //t = 1;
    while(t--){
        solve();
    }
    return 0;
}
