//#include <bits/stdc++.h>
#include <iostream>
//#include <vector>
using namespace std;
int N;
int maxs = INT_MAX;
int main() {
    cin>>N;
    while(N--){
        int a,b;
        cin>>a>>b;
        if(a>b){
            cout<<0;
            return 0;
        }
        if(maxs == INT_MAX){
            maxs = b/a;
        }
        maxs = min(b/a,maxs);
    }
    cout<<maxs;
    return 0;
}