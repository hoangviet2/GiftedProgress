#include <iostream>
using namespace std;
int main(){
    int testcase;
    cin>>testcase;
    while(testcase--){
        int n;
        cin>>n;
        if(n%4!=0){
            cout<<"NO"<<"\n";
        }else{
            cout<<"YES"<<"\n";
        int sumOdd = 0;
        int sumEven = 0;
        int odd = 2;
        int even = 1;
        for(int i=0;i<n/2;++i){
            sumOdd+=odd;
            cout<<odd<<" ";
            odd+=2;
            
        }
        for(int i=0;i<n/2-1;++i){
            sumEven+=even;
            cout<<even<<" ";
            even+=2;
        }
        cout<<sumOdd - sumEven<<"\n";
        }
    }
}
