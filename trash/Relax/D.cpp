#include <iostream>
using namespace std;
int main(){
    int testcase = 1;
    //cin>>testcase;
    while(testcase--){
        int n;
        cin>>n;
        for(int i=n+1;i<9999;++i){
            int a,b,c,d;
            int icpoied = i;
            d = icpoied%10;
            icpoied/=10;
            c = icpoied%10;
            icpoied/=10;
            b = icpoied%10;
            icpoied/=10;
            a = icpoied%10;
            icpoied/=10;
            if(a!=b && a!=c && a!=d && b!=c && b!=d && c!=d){
                cout<<i<<"\n";
                return 0;
            }
        }
    }
    return 0;
}