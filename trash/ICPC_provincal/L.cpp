#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <string>
using namespace std;
typedef long long ll;
vector<ll> oil;
int n;
ll sum = 0;
ll sumEven = 0;
ll sumOdd = 0;
string operations;
void input(){
    cin>>n;
    for(int i=0;i<n;++i){
        ll temp;
        cin>>temp;
        oil.push_back(temp);
        if(temp%2 == 0){
            sumEven+=temp;
        }else{
            sumOdd+=temp;
        }
        sum+=temp;
    }
    getline(cin,operations);
    getline(cin,operations);
}

int main(){
    input();
    for(ll i=0;i<operations.length();++i){
        if(operations[i] == '0'){
            sum -= sumEven/2;
            
        }else{
            sum -= 
        }
        cout<<sum<<"\n";
    }
    return 0;
}
