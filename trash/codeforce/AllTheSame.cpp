// https://codeforces.com/group/eK9nrAK5an/contest/355263/problem/F
#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define ll long long
void allTheSame(){
    int ans = 0;
    int sizes;
    cin>>sizes;
    vector<int> a(sizes);
    for(int i=0;i<sizes;++i){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    if(a[0]==a[sizes-1]){
        cout<<-1<<"\n";
        return;
    }
    for(int i=0;i<sizes;++i){
        ans=__gcd(ans,a[i]-a[0]);
    }
    cout<<ans<<"\n";
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout<<fixed;
    cout<<setprecision(10);
    int testcase;
    cin>>testcase;
    while(testcase--){
        allTheSame();
    }
    return 0;
}