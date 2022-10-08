#include <bits/stdc++.h>

using namespace std;

int getIthbit(int n,int i){
    int mask = (1<<i);
    return (n&mask) > 0 ? 1 : 0;
}

void cleartithbit(int &n,int i){
    int mask = ~(1<<i);
    n = n&mask; //AND
}

void setithbit(int &n, int i){
    int mask = (1<<i);
    n = n|mask; // OR
}

void updateithbit(int &n,int i,int v){
    cleartithbit(n,i);
    int mask = (v<<i);
    n = n|mask; //OR
}
void clearthelastithbit(int &n,int i){
    int mask = (-1<<i);
    n = n&mask;
}

void clearinrange(int &n,int i,int j){
    int a  = (~0) << (j+1);
    int b = (1<<i) - 1;
    int mask = a|b;
    n = n&mask;
}

void replacebit(int &n,int i,int j,int m){
    clearinrange(n,i,j);
    int mask = (m<<i);
    n = n | mask;
}

bool checkPowerOf2(int n){
    return (n &(n-1)) == 0;
}

int countsbit(int n){
    int count = 0;
    while(n>0){
        int lastBit = (n&1);
        count+=lastBit;
        n = n>>1;
    }
    return count;
}

int countsbitFaster(int n){
    int ans = 0;
    while(n>0){
        n = n&(n-1);
        ++ans;
    }
    return ans;
}

int convertToBin(int n){
    int ans = 0;
    int p = 1;
    while(n>0){
        int lastbit = (n&1);
        ans += p*lastbit;
        p *= 10;
        n = n>>1;
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    cout<<convertToBin(n);
    return 0;
}