#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n,temp;
    long long int answer = 0;
    long long int total = 0;
    vector<long long int> numberCollection;
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>temp;
        numberCollection.push_back(temp);
        total += temp;
    }
    int times = n-1;
    sort(numberCollection.begin(),numberCollection.end());
    for(int i=n-1;i>0;--i){
        // tổng chênh lệch của 1 số với các số khác = n-1 nhân với số đó trừ cho tổng các số còn lại
        answer += ((times)*numberCollection[i]) - (total-numberCollection[i]);
        total -= numberCollection[i];
        times-=1;
    }
    cout<<answer;
    return 0;
}