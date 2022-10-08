#include <bits/stdc++.h>
using namespace std;

void slove(){
    long long n;
    cin>>n;
    long long ncopied = n;
    long long nums = 0;
    while(ncopied){
        ++nums;
        ncopied/=10;
    }
    //cout<<999999999<<"\n";
    long long power = (int)pow(10,nums-1);
    cout<<n-power<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while (t--){
        slove();
    }
    
    return 0;
}