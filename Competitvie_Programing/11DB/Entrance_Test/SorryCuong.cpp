#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
int main() {
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;++i){
        cin>>a[i];
    }
    int cnt = 1;
    vector<int> counts;
    for(int i=1;i<n;++i){
        if(a[i-1] == a[i]){
            cnt++;a
        }else{
            counts.push_back(cnt);
            cnt = 1;
        }
    }
    counts.push_back(cnt);
    int mins = 0;
    n = counts.size();
    for(int i=0;i<n-1;++i){
        mins = max(mins,min(counts[i+1],counts[i]));
    }
    cout<<mins*2;
    return 0;
}