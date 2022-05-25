#include <iostream>
#include <algorithm>
using namespace std;
int n;
int maxs=INT_MIN;
int indexs = 0;
int main(){
    cin>>n;
    for(int i=0;i<n;++i){
        int temp;
        cin>>temp;
        if(maxs<=temp){
            maxs = temp;
            indexs = i;
        }
    }
    cout<<maxs<<" "<<indexs+1;
    return 0;
}