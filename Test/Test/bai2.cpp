// C++ program for the above approach
#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <fstream>
using namespace std;
vector<int> arr;
int N,temp;
ifstream Inp;
ofstream Oup;
using namespace std;
int maxLengthSubsequence(vector<int> arr, int N){
    priority_queue<int> priqueue;
    int S = 0;
    for (int i = 0; i < N; i++) {
        S += arr[i];
        priqueue.push(arr[i]);
        while (S > 0) {
            S -= priqueue.top();
            priqueue.pop();
        }
    }
    return priqueue.size();
}
void Input(){
    Inp>>N;
    for(int i=0;i<N;++i){
        Inp>>temp;
        arr.push_back(temp);
    }
    return;
}
int main(){
    Inp.open("bai2.inp");
    Oup.open("bai2.out");
    Input();
    Oup<<maxLengthSubsequence(arr, N);
    Oup.close();
    Inp.close();
    return 0;
}
