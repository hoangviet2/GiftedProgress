#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int testcase;
    cin>>testcase;
    while(testcase--){
        int n;
        cin>>n;
        if(n%2!=0){
            cout<<-1<<"\n";
        }else{
            cout<<0<<" "<<n/2<<" "<<0<<"\n";
        }
    }
    return 0;
}