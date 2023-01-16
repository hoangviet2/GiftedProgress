#include <iostream>
#include <queue>
typedef long long ll;
using namespace std;
queue<ll> a;
bool isEmpty(queue<ll> someQueue){
    return someQueue.size()==0;
}
int main(){
    ll n,temp,addition;
    cin>>n;
    for(ll i=0;i<n;++i){
        cin>>temp;
        if(temp==1){
            cin>>addition;
            //cout<<"Addition is"<<addition<<endl;
            a.push(addition);
        }else if(temp==2){
            if(!isEmpty(a)){
                cout<<a.front()<<"\n";
            }else{
                cout<<"-1"<<"\n";
            }
        }else{
            if(!isEmpty(a)){
                a.pop();
            }
        }
    }
    return 0;
}