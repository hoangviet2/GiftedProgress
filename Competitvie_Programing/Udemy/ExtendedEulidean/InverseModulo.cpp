#include <bits/stdc++.h>
using namespace std;

pair<int,pair<int,int> > extendedGCD(int a,int b){
    if(b==0){
        return make_pair(1,make_pair(0,a));
    }
    pair<int,pair<int,int> > preRes = extendedGCD(b,a%b);
    int smallX = preRes.first;
    int smallY = preRes.second.first;
    int gcd = preRes.second.second;

    //pair<int,int> ans = make_pair(preRes.first,preRes.first-(a/b)*preRes.second);
    int x = smallY;
    int y = smallX - ((a/b)*smallY );

    return make_pair(x,make_pair(y,gcd));
}

// Multiplicative modulo inverse
int MMI(int a,int m){
    pair<int,pair<int,int> > res = extendedGCD(a,m);
    int gcd = res.second.second;
    if(gcd!=1){
        cout<<"DOESn't exist";
        return -1;
    }else{
        return (res.first%m+m)%m;
    }
}

int main(){
#ifndef ONLINE_JUDGE

    freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a,m;
    cin>>a>>m;
    cout<<MMI(a,m);
    return 0;
}