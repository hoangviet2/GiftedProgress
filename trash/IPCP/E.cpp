#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
typedef long long ll;
using namespace std;
map<string,int> election;
int main(){
    int canidates,fans;
    cin>>canidates>>fans;
    for(int i=0;i<=canidates;++i){
        string canidate;
        getline(cin,canidate);
        election[canidate]++;
    }
    for(int i=0;i<fans;++i){
        string canidate;
        getline(cin,canidate);
        if(election[canidate]>=1){
            election[canidate]++;
        }
    }
    int maxs = INT_MIN;
    for(auto element:election){
        maxs = max(element.second,maxs);
    }
    for(auto element:election){
        if(element.second==maxs){
            cout<<element.first;
        }
    }
    return 0;
}
