#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //cout<<"Hello world"<<"\n";
    int t;
    cin>>t;
    while (t--){
        int numsones = 0;
        for(int i=0;i<4;++i){
            int temp;
            cin>>temp;
            if(temp){
                ++numsones;
            }
        }
        if(numsones == 0){
            cout<<0<<"\n";
        }else if(numsones == 4){
            cout<<2<<"\n";
        }else{
            cout<<1<<"\n";
        }
    }
    
    return 0;
}