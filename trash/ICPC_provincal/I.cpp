#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <string>
using namespace std;
typedef long long ll;
vector<ll> numbers;
int n;
ll ans = 0;
void input(){
    cin>>n;
    for(int i=0;i<n;++i){
        int temp;
        cin>>temp;
        numbers.push_back(temp);
    }
}

int main(){
    input();
    for(int i=0;i<n-1;++i){
        for(int j=i+1;j<n;++j){
            if(numbers[i]>numbers[j]){
                ++ans;
            }
        }
    }
    cout<<ans;
    return 0;
}
