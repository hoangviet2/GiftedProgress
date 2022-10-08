#include <bits/stdc++.h>
using namespace std;
int powr(int a,int b){
    int res = 1;
    while(b){
        if(b&1){
            res*=a;
        }
        a*=a;
        b/=2;
    }
    return res;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //cout<<"Hello world"<<"\n";
    cout<<powr(3,3);
    
    return 0;
}