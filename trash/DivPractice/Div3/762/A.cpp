#include <string>
#include <iostream>
using namespace std;

int main(){
    int testcase;
    cin>>testcase;
    string line;
    while(testcase--){
        cin>>line;
        if(line.length()%2 != 0){
            cout<<"NO"<<"\n";
        }else{
            string second,first;
            first = line.substr(0,line.length()/2);
            second = line.substr(line.length()/2,line.length()-1);
            if(first == second){
                cout<<"YES"<<"\n";
            }else{
                cout<<"NO"<<"\n";
            }
        }
    }
    return 0;
}