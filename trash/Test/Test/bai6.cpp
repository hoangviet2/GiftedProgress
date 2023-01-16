// C++ program to implement
// the above approach

#include <iostream>
#include <queue>
#include <fstream>
using namespace std;
ifstream Inp;
ofstream Oup;
vector<int> arr;
int N,temp;
int findSmallestNumLeft(vector<int> arr, int N){
    priority_queue<int> PQ;
    for (int i = 0; i < N; i++) {
        PQ.push(arr[i]);
    }
    while (PQ.size() > 1) {
        int top1 = PQ.top();
        PQ.pop();
        int top2 = PQ.top();
        PQ.pop();
        PQ.push((top1 + top2 + 1) / 2);
    }

    return PQ.top();
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
    Inp.open("bai6.inp");
    Oup.open("bai6.out");
    Input();
    Oup<<findSmallestNumLeft(arr, N);
    Inp.close();
    Oup.close();
    return 0;
}
