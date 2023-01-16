#include <iostream>
#include <cmath>
#include <set>
using namespace std;
typedef long long ll;
int slove(int n){
    set<int> a;
    for(int i=1;i*i*i<=n;++i){
        a.insert(i*i*i);
    }
    for(int i=1;i*i<=n;++i){
        a.insert(i*i);
    }
    return a.size();
}
int main(){
    int testcase;
    cin>>testcase;
    while(testcase--){
        int n;
        cin>>n;
        cout<<slove(n)<<"\n";
    }
    return 0;
}