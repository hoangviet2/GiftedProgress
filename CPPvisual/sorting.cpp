#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
int main(){
    ll n,temp;
    vector<ll> collectionNumber;
    cin>>n;
    for(ll i=0;i<n;++i){
        cin>>temp;
        collectionNumber.push_back(temp);
    }
    sort(collectionNumber.begin(),collectionNumber.end());
    for(ll i=0;i<n-1;++i){
        cout<<collectionNumber[i]<<" ";
    }
    cout<<collectionNumber[collectionNumber.size()-1];
    return 0;
}