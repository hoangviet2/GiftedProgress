// C++ program for the above approach

#include <vector>
#include <queue>
#include <iostream>
#include <fstream>
using namespace std;
ifstream Inp;
ofstream Oup;
vector<int> vec;
int N,K,temp;
void kthSmallest(vector<int> v, int N, int K){
    priority_queue<int> heap1;
    for (int i = 0; i < N; ++i) {
        heap1.push(v[i]);
        if (heap1.size() > K) {
            heap1.pop();
        }
    }
    cout << heap1.top() << endl;
}
void Input(){
    Inp>>N;
    for(int i=0;i<N;++i){
        Inp>>temp;
        vec.push_back(temp);
    }
    Inp>>K;
    return;
}
int main(){
    Inp.open("bai7.inp");
    Oup.open("bai7.out");
    Input();
    kthSmallest(vec, N, K % N);
    Inp.close();
    Oup.close();
    return 0;
}
