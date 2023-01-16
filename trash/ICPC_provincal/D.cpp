#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;
typedef long long ll;
vector<ll> players;
int n;
ll assasin,shelter,safezone;
ll ans = 0;
void input(){
    cin>>n;
    for(int i=0;i<n;++i){
        ll temp;
        cin>>temp;
        if(temp<0){
            temp = temp*(-1);
        }
        players.push_back(temp);
    }
    cin>>assasin>>shelter;
    safezone = abs(assasin-shelter);
}

int main(){
    input();
    for(int i=0;i<n;++i){
        if(abs(players[i]-shelter) <= safezone){
            ++ans;
        }
    }
    if(ans%2 != 0){
        ++ans;
    }
    cout<<ans/2;
    return 0;
}
