// https://codeforces.com/group/eK9nrAK5an/contest/355263/problem/A
#include <iostream>
using namespace std;
typedef long long ll;
ll testcases, xo, NumberOfJump;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> testcases;
    while(testcases--){
        cin >> xo >> NumberOfJump;
        ll rem = NumberOfJump % 4, sign = 1;
        if(xo % 2 == 0){
            sign = -1;
        }
        if(rem == 0){
            cout << xo << "\n";
        }else if(rem == 1){
            cout << xo + sign*NumberOfJump << "\n";
        }else if(rem == 2){
            cout << xo - sign << "\n";
        }else{
            cout << xo - sign*(NumberOfJump + 1) << "\n";   
        }      
    }
}