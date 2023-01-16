#include <iostream>

using namespace std;

int main(){
    int n,temp;
    int ans = 1;
    int count = 0;
    int maxs = INT_MIN;
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>temp;
        if(temp<0){
            ++count;
            maxs = max(temp,maxs);
        }else if (){
            
        }
        ans *= abs(temp);
    }
    if(count%2!=0{

    }
    return 0;
}