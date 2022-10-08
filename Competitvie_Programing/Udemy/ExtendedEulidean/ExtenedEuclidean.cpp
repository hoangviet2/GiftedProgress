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

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a,b;
    cin>>a>>b;
    pair<int,pair<int,int> > res = extendedGCD(a,b);
    cout<<res.first<<" "<<res.second.first<<" "<<res.second.second;
    return 0;
}