#include <iostream>
#include <vector>
#include <algorithm>
typedef long long ll;
using namespace std;
vector<ll> a;
bool isEmpty(vector<ll> someSet){
    return someSet.size()==0;
}
int main(){
    ll n,temp,addition;
    cin>>n;
    for(ll i=0;i<n;++i){
        cin>>temp;
        if(temp==1){
            cin>>addition;
            //cout<<"Addition is"<<addition<<endl;
            a.push_back(addition);
        }else if(temp==2){
            if(!isEmpty(a)){
                cout<<a[0]<<"\n";
                a.erase(a.begin());
            }else{
                cout<<"-1"<<"\n";
            }
        }else if(temp==3){
            sort(a.begin(),a.end());
        }
    }
    return 0;
}