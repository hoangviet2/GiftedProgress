#include <iostream>
#include <vector>
#include <algorithm>
typedef long long ll;
using namespace std;
int main(){
    int diameter, time, papers;
    cin>>diameter>>time>>papers;
    for(int i=0;i<papers;++i){
        int a,b;
        cin>>a>>b;
        if(a<diameter || b<diameter){
            cout<<"NO"<<"\n";
        }else{
            cout<<"YES"<<"\n";
        }
    }
    return 0;
}
