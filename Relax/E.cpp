#include <iostream>
#include <map>
#include <string>
using namespace std;
map<char,int> a;
int main(){
    int testcase = 1;
    //cin>>testcase;
    while(testcase--){
        int n;
        cin>>n;
        for(int i=0;i<n;++i){
            char temp;
            cin>>temp;
            a[tolower(temp)]++;
        }
        if(a.size()==26){
            cout<<"YES"<<"\n";
        }else{
            cout<<"NO"<<"\n";
        }
    }
    return 0;
}