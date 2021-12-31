#include <iostream>
#include <string>
using namespace std;
int main(){
    int testcase;
    cin>>testcase;
    while(testcase--){
        int a,b,c;
        int ans = 0;
        cin>>a>>b>>c;
        while(a<=c && b<=c){
            if(a<=b){
                a+=b;
            }else{
                b+=a;
            }
            ++ans;
        }
        cout<<ans<<"\n";
    }
    return 0;
}