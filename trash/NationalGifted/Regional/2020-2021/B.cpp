#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
vector<ll> a;
ll count(vector<ll> numbers){
    ll ans = 1;
    for(int i=0;i<numbers.size()-1;++i){
        if(numbers[i]!=numbers[i+1]){
            ++ans;
        }
    }
    return ans;
}
void slove(){
    int N,Q;
    ll ans = 0;
    cin>>N;
    for(int i=0;i<N;++i){
        ll temp;
        cin>>temp;
        a.push_back(temp);
    }
    cin>>Q;
    for(int i=0;i<Q;++i){
        ll replaceVal,pos;
        cin>>pos>>replaceVal;
        a[pos-1] = replaceVal;
        cout<<count(a)<<"\n";
    }
}
int main(){
    slove();
    return 0;
}