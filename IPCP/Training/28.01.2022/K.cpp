//#include<bits/stdc++.h> 
#include <map>
#include <string>
#include <unordered_map>
#include <iostream>
using namespace std; 
typedef unsigned long long ull; 
const int MAXN=1e6+1; 
const int seed=13331; 
unordered_map<ull,int> mp; 
ull h[MAXN],p[MAXN]; 
string s; 
int slen; 
int check(int len){
    int l=1,r=len,value,cnt=0; 
    mp.clear(); 
    for(;r<slen;++l,++r){
        value=h[r]-h[1-1]*p[len]; 
        mp[value]++; 
        if(mp[value]==1){
            ++cnt; 
        }else if(mp[value]==2){
            --cnt; 
        }
    }
    return cnt; 
} 
int main() { 
    std::ios::sync_with_stdio(false); 
    std::cin.tie(0); 
    std::cout.tie(0); 
    cin>>s; 
    s="6"+s; 
    slen=s.length(); 
    for(int i=1;i<slen;++i){
        h[i]=h[i-1]*seed+s[i]-'A'+1;
    } 
    p[0]=1; 
    for(int i=1;i<=slen;++i) {
        p[i]=p[i-1]*seed;
    } 
    int minlen=1,maxlen=slen-1,mid; 
    while(minlen<maxlen){
        mid=(minlen+maxlen)>>1; 
        if(check(mid)){
            maxlen=mid; 
        }else {
            minlen=mid+1; 
        }
    }
    int l=1,r=minlen,value; 
    mp.clear(); 
    for(;r<slen;++l,++r){
        value=h[r]-h[1-1]*p[minlen]; 
        mp[value]++;
        
    }
    l=1,r=minlen;
    for(;r<slen;++l,++r) {
        value=h[r]-h[1-1]*p[minlen]; 
        if(mp[value]==1) {
            cout<<s.substr(1,minlen); 
            break; 
        }
    }
    return 0; 
} 
