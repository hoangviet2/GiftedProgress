#include <bits/stdc++.h>
using namespace std;

int main(){
#ifndef ONLINE_JUDGE

    //freopen("input.txt", "r", stdin);

    freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //cout<<"Hello world"<<"\n";
    int n;
    cin>>n;
    int maxA = INT_MIN;
    int maxB = INT_MIN;
    for(int i=0;i<n;++i){
        int temp;
        cin>>temp;
        maxA = max(temp,maxA);
    }
    cin>>n;
    for(int i=0;i<n;++i){
        int temp;
        cin>>temp;
        maxB = max(temp,maxB);
    }
    cout<<maxA<<" "<<maxB;
    return 0;
}