#include <algorithm>
#include <iostream>
using namespace std;

int main(){
    int testcase;
    cin>>testcase;
    while(testcase--){
        int maxs = INT_MIN;
        int mins = INT_MAX;
        int n;
        cin>>n;
        for(int i=0;i<n;++i){
            int temp;
            cin>>temp;
            maxs = max(maxs,temp);
            mins = min(mins,temp);
        }
        cout<<maxs-mins<<"\n";
    }
    return 0;
}