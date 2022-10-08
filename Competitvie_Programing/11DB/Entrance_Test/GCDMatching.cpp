#include<bits/stdc++.h>

#define F first
#define S second
#define pb push_back

using namespace std;
int main() {
    int n;
    cin>>n;
    int odd = 0, even = 0;
    for(int i=0;i<n;++i){
        int temp;
        cin>>temp;
        if(temp%2 == 0){
            ++even;
        }else{
            ++odd;
        }
    }
    int addition = (odd>even) ? odd-even : 0;
    cout<< (min(odd,even)) + (addition/2);
    return 0;
}