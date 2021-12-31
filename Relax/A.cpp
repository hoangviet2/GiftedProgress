#include <iostream>
#include <string>
using namespace std;
int main(){
    int testcase = 1;
    //cin>>testcase;
    while(testcase--){
        string line;
        cin>>line;
        string ans = "";
        for(int i=0;i<line.length();++i){
            char a = tolower(line[i]);
            if(a != 'a' && a!='o' &&a != 'y' && a!='e' && a!='u' && a!='i'){
                ans+='.';
                ans+=a;
            }
        }
        cout<<ans;
    }
    return 0;
}