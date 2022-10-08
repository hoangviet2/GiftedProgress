#include <bits/stdc++.h>

using namespace std;

int countsbitFaster(int n){
    int ans = 0;
    while(n>0){
        n = n&(n-1);
        ++ans;
    }
    return ans;
}

bool cmp(int a,int b){
    int numsoneA = countsbitFaster(a);
    int numsoneB = countsbitFaster(b);
    if(numsoneA == numsoneB){
        return a<b;
    }
    return numsoneA(a) < numsoneA(b);
}

vector<int> sortByBits(vector<int> arr) {
    sort(arr.begin(),arr.end(),cmp);
    return arr;
}

int main(){

}