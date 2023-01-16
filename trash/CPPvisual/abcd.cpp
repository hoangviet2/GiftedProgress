#include <bits/stdc++.h>
using namespace std;
int main(){
    long long int n;
    long long int maxs;
    vector<int> a;
    cin>>n;
    for(long long int i=0;i<n;++i){
        int temp;
        cin>>temp;
        a.push_back(temp);
        maxs = max(temp,maxs);
    }

    bool b[maxs+1];
    for(int i=3;i<=maxs;i+=2){
        b[i] = true;
    }
    for(int i=4;i<=maxs;i+=2){
        b[i] = false;
    }
    b[1]=false;
    b[2]=true;
    for(int i=3;i*i<=maxs;i+=2){
        if(b[i] == true){
            for(int j=i*i;j<maxs;j+=2*i){
                b[j] = false;
            }
        }
    }
    
    for(auto element:a){
        if(b[element] || b[element-1] || b[element+1]){
            cout<<1<<"\n";
        }else{
            cout<<0<<"\n";
        }
    }
    return 0;
}