// question link:
#include <iostream>
using namespace std;
int stations,fuel;
int ans = 0;
void slove(){
    cin>>stations>>fuel;
    for(int i=0;i<stations;++i){
        int temp;
        cin>>temp;
        fuel-=temp;
        if(fuel<0){
            cout<<ans+1;
            break;
        }else{
            ++ans;
        }
    }
    return;
}
int main(){
    slove();
    return 0;
}