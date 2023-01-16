//https://codeforces.com/contest/1611/problem/B
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
int testcase;
ll maths,programer;

int main(){
    cin>>testcase;
    while(testcase--){
        cin>>maths>>programer;
        if(maths==programer){
            cout<<(maths+programer)/4<<"\n";
        }else if(maths>programer){
            ll distances = maths-programer;
            maths -= distances;
            distances/=2;
            distances = min(maths,distances);
            maths -= distances;
            programer -= distances;
            distances += (maths+programer)/4;
            cout<<distances<<"\n";
        }else{
            ll distances = programer-maths;
            programer -= distances;
            distances/=2;
            distances = min(programer,distances);
            maths -= distances;
            programer -= distances;
            distances += (maths+programer)/4;
            cout<<distances<<"\n";
        }
    }
    return 0;
}