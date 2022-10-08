#include <bits/stdc++.h>
using namespace std;

void findsub(string s,int n){
    int ind = 0;
    while(n>0){
        int lastbit = n&1;
        if(lastbit){
            cout<<s[ind];
        }
        ++ind;
        n = n>>1;
    }
    cout<<"\n";
}

void generateSubStr(string s){
    int n = s.size();
    // 1<<n = 2^n
    for(int i=0;i<(1<<n);++i){
        findsub(s,i);
    }
    return;
}


int main(){
#ifndef ONLINE_JUDGE

    freopen("input.txt", "r", stdin);

    freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;
    generateSubStr(s);
    //cout<<"Hello world"<<"\n";
    return 0;
}