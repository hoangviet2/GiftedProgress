#include <bits/stdc++.h>
using namespace std;
void slove(){
    map<int,bool> A;
    map<int,bool> B;
    int n;
    cin>>n;
    bool valid = true;
    for(int i=0;i<n;++i){
        int a,b;
        cin>>a>>b;
        if(!A[a] && !A[b] && (a!=b)){
            A[a] = 1;
            A[b] = 1;
        }else if(!B[a] && !B[b] && (a!=b)){
            B[a] = 1;
            B[b] = 1;
        }else{
            valid = false;
        }
    }
    if(valid){
        cout<<"YES"<<"\n";
    }else{
        cout<<"NO"<<"\n";
    }
}
int main(){
#ifndef ONLINE_JUDGE

    //freopen("input.txt", "r", stdin);

    freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        slove();
    }
    return 0;
}