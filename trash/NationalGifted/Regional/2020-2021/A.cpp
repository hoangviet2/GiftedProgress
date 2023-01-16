#include <iostream>
#include <set>
using namespace std;
set<int> sets;
int main(){
    int N,M;
    cin>>N>>M;
    for(int i=0;i<M;++i){
        int a,b;
        cin>>a>>b;
        sets.insert(a);
        sets.insert(b);
        if(sets.size()==N && i>N/2){
            cout<<i;
            return 0;
        }
    }
    return 0;
}
