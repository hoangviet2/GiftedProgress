#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
#define ll long long
using namespace std;
int ans = 0;
string line;
int f[8];
void slove(){
    cin>>line;
    for(int i=1;i<7;++i){
        f[i] = f[i-1];
        if (line[i] == line[i-1]){
            f[i] = max(f[i-1], f[i-2]+2);
        }
        if(i<2){
            continue;
        }
        // aaa
        if ((line[i] == line[i-1]) && (line[i] == line[i-2])){
            f[i] = max(f[i], max(f[i-1], max(f[i-2], f[i-3]+3)));
        }
        // baa,aba,aab
        else if (line[i] == line[i-1] || line[i] == line[i-2] || line[i-1] == line[i-2]){
            f[i] = max(f[i], max(f[i-1], max(f[i-2], f[i-3]+2)));
        }
        if(i<3){
            continue;
        }
        // abac,baca, abab, aabb, abba, baaa, abaa, aaba, aaab, aaaa
        string sub = line.substr(i-3,4);
        if((sub[0]==sub[1] && sub[2]==sub[3]) && (sub[1]==sub[2])){
            f[i] = max(f[i], max(f[i-1], max(f[i-2], max(f[i-3],f[i-4]+5))));
        }
        if(sub[0]==sub[3] && sub[1]==sub[2]){
            f[i] = max(f[i], max(f[i-1], max(f[i-2], max(f[i-3],f[i-4]+4))));
        }
        if(sub[0]==sub[2] && sub[1]!=sub[3]){
            f[i] = max(f[i], max(f[i-1], max(f[i-2], max(f[i-3],f[i-4]+2))));
        }
        if(sub[0]!=sub[2] && sub[1]==sub[3]){
            f[i] = max(f[i], max(f[i-1], max(f[i-2], max(f[i-3],f[i-4]+2))));
        }
        if(sub[0]==sub[1] && sub[2]==sub[3]){
            f[i] = max(f[i], max(f[i-1], max(f[i-2], max(f[i-3],f[i-4]+3))));
        }
        if(sub[0]==sub[2] && sub[1]==sub[3]){
            f[i] = max(f[i], max(f[i-1], max(f[i-2], max(f[i-3],f[i-4]+3))));
        }
        if(sub[0]==sub[1] && sub[1]==sub[2]){
            f[i] = max(f[i], max(f[i-1], max(f[i-2], max(f[i-3],f[i-4]+3))));
        }
        if(sub[1]==sub[2] && sub[2]==sub[3]){
            f[i] = max(f[i], max(f[i-1], max(f[i-2], max(f[i-3],f[i-4]+3))));
        }
        if(sub[0]==sub[2] && sub[2]==sub[3]){
            f[i] = max(f[i], max(f[i-1], max(f[i-2], max(f[i-3],f[i-4]+3))));
        }
        if(sub[0]==sub[1] && sub[1]==sub[3]){
            f[i] = max(f[i], max(f[i-1], max(f[i-2], max(f[i-3],f[i-4]+3))));
        }
    }
    cout<<f[6];
    return;
}

int main(){
    slove();
    return 0;
}
